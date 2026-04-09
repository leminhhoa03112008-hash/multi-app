import requests
import json
import re
import time

FB_GRAPHQL = "https://www.facebook.com/api/graphql/"
FB_HOME = "https://www.facebook.com/"
session = requests.Session()

def parse_cookie(cookie_str: str) -> dict:
    return {k: v for item in cookie_str.split(";") if "=" in item for k, v in [item.strip().split("=", 1)]}

def strip_json(text: str):
    text = text.strip()
    if not text:
        raise Exception("Response trống")
    if text.startswith("for (;;);"):
        text = text[9:]
    try:
        return json.loads(text)
    except json.JSONDecodeError as e:
        print(f"\n⚠️ Lỗi parse JSON: {e}")
        print(f"Response: {text[:200]}")
        raise Exception(f"Response không phải JSON: {str(e)}")

def get_tokens(cookies: dict):
    headers = {
        'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7',
        'accept-language': 'vi,en-US;q=0.9,en;q=0.8,fr-FR;q=0.7,fr;q=0.6',
        'priority': 'u=0, i',
        'sec-ch-prefers-color-scheme': 'light',
        'sec-ch-ua': '"Google Chrome";v="143", "Chromium";v="143", "Not A(Brand";v="24"',
        'sec-ch-ua-full-version-list': '"Google Chrome";v="143.0.7499.182", "Chromium";v="143.0.7499.182", "Not A(Brand";v="24.0.0.0"',
        'sec-fetch-dest': 'document',
        'sec-fetch-mode': 'navigate',
        'sec-fetch-site': 'none',
        'upgrade-insecure-requests': '1',
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/143.0.0.0 Safari/537.36',
    }
    
    r = session.get(FB_HOME, headers=headers, cookies=cookies)
    html = r.text
    
    patterns = {
        "fb_dtsg": r'"DTSGInitData".*?"token":"([^"]+)"',
        "lsd": r'"LSD".*?"token":"([^"]+)"',
        "jazoest": r'jazoest=(\d+)'
    }
    
    tokens = {key: (m.group(1) if (m := re.search(pattern, html)) else None) for key, pattern in patterns.items()}
    
    print(tokens)
    if not all(tokens.values()):
        raise Exception("❌ Không thể đăng nhập – cookie die hoặc checkpoint")
    
    return tokens

def graphql_post(cookies, headers, data):
    try:
        r = session.post(FB_GRAPHQL, headers=headers, cookies=cookies, data=data)
        if r.status_code != 200:
            raise Exception(f"HTTP {r.status_code}")
        return strip_json(r.text)
    except Exception as e:
        raise Exception(f"GraphQL error: {str(e)}")

def get_suggestions(cookies, tokens, uid):
    headers = {
        'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7',
        'accept-language': 'vi,en-US;q=0.9,en;q=0.8,fr-FR;q=0.7,fr;q=0.6',
        'priority': 'u=0, i',
        'sec-ch-prefers-color-scheme': 'light',
        'sec-ch-ua': '"Google Chrome";v="143", "Chromium";v="143", "Not A(Brand";v="24"',
        'sec-ch-ua-full-version-list': '"Google Chrome";v="143.0.7499.182", "Chromium";v="143.0.7499.182", "Not A(Brand";v="24.0.0.0"',
        'sec-fetch-dest': 'document',
        'sec-fetch-mode': 'navigate',
        'sec-fetch-site': 'none',
        'upgrade-insecure-requests': '1',
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/143.0.0.0 Safari/537.36',
    }
    
    data = {
        "av": uid,
        "__user": uid,
        "__a": "1",
        "fb_dtsg": tokens["fb_dtsg"],
        "jazoest": tokens["jazoest"],
        "lsd": tokens["lsd"],
        "fb_api_caller_class": "RelayModern",
        "fb_api_req_friendly_name": "FriendingCometSuggestionsRootQuery",
        "variables": json.dumps({"scale": 1}),
        "doc_id": "24180156278339004",
    }
    
    res = graphql_post(cookies, headers, data)
    edges = res["data"]["viewer"]["people_you_may_know"]["edges"]
    
    return [{
        "uid": e["node"]["id"],
        "name": e["node"]["name"]
    } for e in edges]

def add_friend(cookies, tokens, actor_id, target_uid):
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/143.0.0.0 Safari/537.36",
        "Connection": "keep-alive",
        "Accept": "*/*",
        "Accept-Encoding": "identity",
        "Content-Type": "application/x-www-form-urlencoded",
        "accept-language": "vi,en-US;q=0.9,en;q=0.8,fr-FR;q=0.7,fr;q=0.6",
        "cache-control": "no-cache",
        "origin": "https://www.facebook.com",
        "pragma": "no-cache",
        "priority": "u=1, i",
        "referer": "https://www.facebook.com/friends/suggestions",
        "sec-ch-prefers-color-scheme": "light",
        "sec-ch-ua": "\"Google Chrome\";v=\"143\", \"Chromium\";v=\"143\", \"Not A(Brand\";v=\"24\"",
        "sec-ch-ua-full-version-list": "\"Google Chrome\";v=\"143.0.7499.182\", \"Chromium\";v=\"143.0.7499.182\", \"Not A(Brand\";v=\"24.0.0.0\"",
        "sec-ch-ua-model": "\"\"",
        "sec-ch-ua-platform": "\"Windows\"",
        "sec-ch-ua-platform-version": "\"10.0.0\"",
        "sec-fetch-dest": "empty",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "same-origin",
        "x-fb-friendly-name": "FriendingCometFriendRequestSendMutation"
    }
    
    data = {
        "av": actor_id,
        "__user": actor_id,
        "__a": "1",
        "fb_dtsg": tokens["fb_dtsg"],
        "jazoest": tokens["jazoest"],
        "lsd": tokens["lsd"],
        "fb_api_caller_class": "RelayModern",
        "fb_api_req_friendly_name": "FriendingCometFriendRequestSendMutation",
        "server_timestamps": "true",
        "variables": json.dumps({
            "input": {
                "click_correlation_id": str(int(time.time() * 1000)),
                "click_proof_validation_result": "{\"validated\":true}",
                "friend_requestee_ids": [target_uid],
                "friending_channel": "FRIENDS_HOME_MAIN",
                "warn_ack_for_ids": [],
                "actor_id": actor_id,
                "client_mutation_id": "1"
            },
            "scale": 1
        }),
        "doc_id": "25491427290506954"
    }
    
    return graphql_post(cookies, headers, data)

def check_success(res):
    if res.get("data") and res["data"].get("friend_request_send"):
        friend_requestees = res["data"]["friend_request_send"].get("friend_requestees", [])
        if friend_requestees and friend_requestees[0].get("friendship_status") == "OUTGOING_REQUEST":
            return True
    return False

def main():
    cookie_str = input("👉 Nhập COOKIE Facebook: ").strip()
    cookies = parse_cookie(cookie_str)
    
    uid = cookies.get("c_user")
    if not uid:
        print("❌ Cookie thiếu c_user")
        return
    
    print("[*] Đang đăng nhập..")
    tokens = get_tokens(cookies)
    total_added = 0
    
    try:
        while True:
            users = get_suggestions(cookies, tokens, uid)
            
            if not users:
                print("⚠️ Không có người dùng mới, thử lại...")
                continue
            
            print(f"📋 Tìm thấy {len(users)} người dùng\n")
            
            for u in users:
                try:
                    print(f"➕ Đang add: {u['name']} ({u['uid']})...", end=" ", flush=True)
                    res = add_friend(cookies, tokens, uid, u['uid'])
                    
                    if check_success(res):
                        print("✔ Thành công")
                        total_added += 1
                    else:
                        print("⚠️ Có lỗi")
                    
                    time.sleep(5)
                    
                except Exception as e:
                    print(f"❌ Lỗi: {str(e)}")
                    time.sleep(5)
            
            print(f"\n📊 Tổng đã add: {total_added}")
            
    except KeyboardInterrupt:
        print(f"\n\n✋ Dừng! Tổng đã add được: {total_added} người")

if __name__ == "__main__":
    main()
