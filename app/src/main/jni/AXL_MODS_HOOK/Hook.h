/*
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
*/
#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <Il2Cpp.h>
#include <Tools.h>
#include <Vector3.hpp>
#include <Color.h>

#include "obfuscate.h"
#include "Unity/unity.h"
#include "Class.h"
#include "Rect.h"
//inline static int g_GlHeight, g_GlWidth;
#include "Bools.h"
#include <math.h>
#include <stdio.h>
inline static int g_GlHeight, g_GlWidth;
typedef char PACKAGENAME;
//#include "MemoryPatch.h"
// Khai Báo

#define ICON_FA_TELEGRAM "\xef\x8b\x86"	// U+f2c6

bool AirdropSwitch = false;    

float density = -1;
struct cfg {
    bool aimbot;
    int aim_type = 0;
    int aim_target = 1;
    struct _esp {
        bool Box = true;
        bool Box3D = false;
        bool Line = true;
		bool Info = true;
		//bool Egline = false;
        bool Health = true;
        bool Distance = true;
        bool IsName = true;
        bool Path = false;
        bool Esp360 = true;
        bool Target = true;
    }ESP;
}inline Config;
bool AimWhen3 = false;
bool AimWhen2 = false;
bool box = false;
bool totalEnemies = true;
bool AimWhen1 = true;
//boo prince.Egline = false;
bool showbox1 = false;
bool showline1 = false;
bool camxa = false;
//bool EspGranada = false;
//EspGrenade = !EspGrenade;
bool showline2 = false;
bool AimSilent = false;
bool camcao = false;
bool showline = false;
bool speedrun = false;
bool Firewall = true;
bool isSpeedSafe = false;
bool health = true;
bool Headshot = true;
bool AimNewF = true;
bool UnlimitedHealth = false;   // Off by default
bool fastKill = false;
//bool Reset = false;
bool GoldenAll = false;
bool DoubleGun= false;
bool fastswitch = true;
int isSpeed = 0;  
int Speedx = 0;  
//int showline = 0;

static float maxKillSpeed = 1000.0f; // default value
/*
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
*/



//bool AirdropSwitch = false;
struct MassKill {
float Sucks1 = 9.0f;
bool Sucks = false;
float FrontOffset = 0.5f;
}Mass;

//bool AimNewF =false;
//int showline = 0;
const char* line[] = {OBFUSCATE("Esp Line 1"),OBFUSCATE("Esp Line 2"),OBFUSCATE("Esp Line 3")};

int showbox = 1;
//MemoryPatch  Resetguest,DouleGun,nightmod,WallHack2;

//const char* box[] = {OBFUSCATE("Esp Box"),OBFUSCATE("Esp Box 3D")};

struct sColor {
        float circle[4] = {0 / 255.0f, 255 / 255.0f, 0 / 255.0f, 255 / 255.0f};

		float box[4] = {255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f};
        float line1[4] = {255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f};
        float box1[4] = {255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f};
        float box3d1[4] = {255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f};
        float info1[4] = {0 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};

        float line2[4] = {255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};
        float box2[4] = {255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};
        float box3d2[4] = {255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};
        float info2[4] = {255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};
};
sColor Color;
//bool Reset = false;



bool isOutsideScreen(ImVec2 pos, ImVec2 screen) {
    if (pos.y < 0) {
        return true;
    }
    if (pos.x > screen.x) {
        return true;
    }
    if (pos.y > screen.y) {
        return true;
    }
    return pos.x < 0;
}

ImVec2 pushToScreenBorder(ImVec2 Pos, ImVec2 screen, int offset) {
    int x = (int) Pos.x;
    int y = (int) Pos.y;
    
    if (Pos.y < 0) {
        y = -offset;
    }
    
    if (Pos.x > screen.x) {
        x = (int) screen.x + offset;
    }
    
    if (Pos.y > screen.y) {
        y = (int) screen.y + offset;
    }
    
    if (Pos.x < 0) {
        x = -offset;
    }
    return ImVec2(x, y);
}

static float tm = 127 / 255.f;

void(*Set_Aim)(void* _this);
void _Set_Aim(void* _this) {
    return;
    return Set_Aim(_this);
}

// BYPASS
bool(*Bypass)(void* bypass); 
bool _Bypass(void* bypass) { 
    return false;
}

bool(*FixGame)(void* _this);
bool _FixGame(void* _this) {
    if (_this != NULL) {
        return true;
    }
}

bool(*BypassESP)(void* _this);
bool _BypassESP(void* _this) {
    return true;
}

bool(*Bypass2)(void* _this);
bool _Bypass2(void* _this) {
    return true;
}

void DrawCircleHealth(ImVec2 position, int health, int max_health, float radius) {
    float a_max = ((3.14159265359f * 2.0f));
    ImU32 healthColor = IM_COL32(45, 180, 45, 255);
    if (health <= (max_health * 0.6)) {
        healthColor = IM_COL32(180, 180, 45, 255);
    }
    if (health < (max_health * 0.3)) {
        healthColor = IM_COL32(180, 45, 45, 255);
    }
    ImGui::GetForegroundDrawList()->PathArcTo(position, radius, (-(a_max / 4.0f)) + (a_max / max_health) * (max_health - health), a_max - (a_max / 4.0f));
    ImGui::GetForegroundDrawList()->PathStroke(healthColor, ImDrawFlags_None, 4);
}

void drawText2(int x, int y, long color, const char *str, float size) {
    ImGui::GetBackgroundDrawList()->AddText(NULL, size, ImVec2(x, y), color, str);
}

void DrawRectFilled(int x, int y, int w, int h, ImColor color) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
}

void DrawRectFilledHealth(int x, int y, int w, int h, ImVec4 color) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(color), 0, 0);
}

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, int T) {
    ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), color);
}


void DrawHealths(Rect box, float entityHealth, float maxHealth, int TeamID, const char* name, long color) {
    float x = box.x - (140 - box.w) / 2;
    float y = box.y;
    char dis[20];
 

    char TeamText[20];
    sprintf(TeamText, "%d", (int)TeamID);
    ImVec4 HPColor = ImVec4{1, 1, 0, 127 / 255.f};

    if (entityHealth < maxHealth) {
        float healthPercentage = entityHealth / maxHealth;

        if (healthPercentage < 0.3f) {
            HPColor = ImVec4{0.5f, 0.0f, 0.0f, 127 / 255.f}; 
        } else if (healthPercentage < 0.6f) {
            HPColor = ImVec4{1, 0, 0, 127 / 255.f}; 
        }
    }

    tm = 100.f / 255.f;
    DrawRectFilled(x - strlen(name), y - 41, 120 + strlen(name) * 2, 20, color); 
    tm = 255.f / 255.f;
    DrawRectFilled(x - strlen(name), box.y - 41, 25, 20, color);
    if (strlen(TeamText) < 2) {
        drawText2(x + 6 - strlen(name), box.y - 42, ImColor(255,255,255), TeamText, 18.943);
    } else {
        drawText2(x - strlen(name), box.y - 42, ImColor(255,255,255), TeamText, 18.943);
    }
    drawText2(x + 28 - strlen(name), y - 43, ImColor(255,255,255), name, 18.943);
    float maxWidth = 120; // Độ dài tối đa của thanh máu
    float healthBarWidth = entityHealth * maxWidth / maxHealth; // Độ dài thanh máu dựa trên tỷ lệ máu hiện tại và máu tối đa
    DrawRectFilledHealth(x - maxWidth / 2, y - 18, healthBarWidth, 8, HPColor);// cập nhật vị trí và kích thước của thanh máu
    drawText2(x + 125 + strlen(name), y - 43, ImColor(255,255,255), dis,18.943);
    DrawTriangle(box.x + box.w / 2 - 10, y - 8, box.x + box.w / 2 + 15 - 10, y - 8, box.x + box.w / 2 - 2, y, ImColor(255,255,255), 1);
}

static float SetFieldOfView = 0, GetFieldOfView = 0;

float (*get_deltaTime)();
float smoothSpeedAIM = 5; 
void *MyPlayer = NULL;
bool Drone;

const float RADAR_SIZE = 200.0f;
const ImVec2 RADAR_CENTER(100.0f, 100.0f);

float x,y;
float enemy1 = 2.0f;

inline void DrawAIMBOT(float screenWidth, float screenHeight) { 
}

void DroneView() {
    if (GetFieldOfView == 0) {
        GetFieldOfView = get_fieldOfView();
    }
    if (SetFieldOfView > 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView + SetFieldOfView);
    }
    if (SetFieldOfView == 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView);
    }
}

Quaternion GetRotationToTheLocation(Vector3 Target, float Height, Vector3 MyEnemy) {
return Quaternion::LookRotation((Target + Vector3(0, Height, 0)) - MyEnemy, Vector3(0, 1, 0));
}

bool isVisible(void *enemy)  {
    if(enemy != NULL)  {
         void *hitObj = NULL;
         auto Camera = Transform_GetPosition(Component_GetTransform(Camera_main()));
         auto Target = Transform_GetPosition(Component_GetTransform(Player_GetHeadCollider(enemy)));
         return !Physics_Raycast(Camera, Target, 12, &hitObj);
    }
    return false;
}

void *GetClosestEnemy() {
    float shortestDistance = 9999;
    void* closestEnemy = NULL;   
     
    void* get_MatchGame = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(get_MatchGame);

    if (LocalPlayer != NULL && get_MatchGame != NULL && Enable && get_MatchGame) {
        monoDictionary<uint8_t *, void **> *players = *(monoDictionary<uint8_t*, void **> **)((long)get_MatchGame + ListPlayer);
        
        for (int u = 0; u < players->getNumValues(); u++) {
            void* Player = players->getValues()[u]; 
            if (Player != NULL && !get_isLocalTeam(Player) && !get_IsDieing(Player) && get_isVisible(Player) && get_MaxHP(Player)) {    
                Vector3 PlayerPos = getPosition(Player);
                Vector3 LocalPlayerPos = getPosition(LocalPlayer);
                Vector3 pos2 = WorldToScreenPoint(Camera_main(), PlayerPos);
                bool isFov1 = isFov(Vector3(pos2.x, pos2.y), Vector3(g_GlWidth / 2, g_GlHeight / 2), Fov_Aim);
            
                
                
                
                float distance = Vector3::Distance(LocalPlayerPos, PlayerPos);
                if (distance < 1000) {
                    Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
                    float angle = Vector3::Angle(targetDir, GetForward(Component_GetTransform(Camera_main()))) * 100.0;             
            
                    if (angle <= Fov_Aim && isFov1 && angle < shortestDistance) {
                     if(isVisible(Player)) {
                        shortestDistance = angle;
                        closestEnemy = Player;
                    }
                   }
                }
            }
        }
    }
    return closestEnemy;
}
/*
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
*/
void (*LateUpdate)(void *Player);
void _LateUpdate(void *Player){
	
	 
		
if (Player != NULL) {
if (Aimbot) {

	 int totalEnemies = 0;
void* CurrentMatch = Curent_Match();
void* closestEnemy = GetClosestEnemy();
void* LocalPlayer = GetLocalPlayer(CurrentMatch);

if (closestEnemy != NULL && LocalPlayer != NULL && CurrentMatch != NULL) {
    Vector3 EnemyLocation = GetHeadPosition(closestEnemy);
    Vector3 PlayerLocation = CameraMain(LocalPlayer);
    Quaternion PlayerLook = GetRotationToTheLocation(EnemyLocation, 0.1f, PlayerLocation);
    bool IsScopeOn = get_IsSighting(LocalPlayer);
    bool IsFiring = get_IsFiring(LocalPlayer);    
  
    if (AimWhen1) {
        set_aim(LocalPlayer, PlayerLook);
    }
    else if (AimWhen2 && IsFiring) {
        set_aim(LocalPlayer, PlayerLook);
    }
    else if (AimWhen3 && IsScopeOn) {
        set_aim(LocalPlayer, PlayerLook);
    }
  }
  }
  }
  LateUpdate(Player);
}
void (*orig_mrSilentAim)(void *, float, float);
void hook_mrAimSilent(void *_this, float a1, float a2) {
if (_this != nullptr) {
if(Enable) {
if (AimSilent) {
void *CurrentMatch = Curent_Match();
if (CurrentMatch != NULL) {
void* LocalPlayer = GetLocalPlayer(CurrentMatch);
if (LocalPlayer != NULL)  {
bool visible = isVisible(LocalPlayer);
if (visible) {
if (get_IsFiring(GetLocalPlayer(CurrentMatch))) {
return;
} else {
orig_mrSilentAim(_this, a1, a2);
}
}
}
}
}
}
orig_mrSilentAim(_this, a1, a2);
}
}
	

inline void DrawESP(float screenWidth, float screenHeight) {
    ImDrawList* draw = ImGui::GetBackgroundDrawList();
    if (!draw) return;
      if (isSpeedSafe) {
        isSpeed = 4;
    } else {
        isSpeed = 0;
    }
         

        if (Enable) {
        void* current_Match = Curent_Match();
        void* local_player = GetLocalPlayer(current_Match);

        if (local_player && current_Match) {
            auto* players = *(monoDictionary<uint8_t*, void**>**)((long)current_Match + ListPlayer);
            void* camera = Camera_main();

            if (players && camera) {
                for (int u = 0; u < players->getNumValues(); u++) {
                    void* closestEnemy = players->getValues()[u];
                    if (closestEnemy != local_player && closestEnemy && get_isVisible(closestEnemy) && !get_isLocalTeam(closestEnemy)) {
                        Vector3 Toepos = getPosition(closestEnemy);
                        Vector3 Toeposi = WorldToScreenPoint(camera, Toepos);
                        if (Toeposi.z < 1) continue;

                        Vector3 HeadPos = getPosition(closestEnemy) + Vector3(0, 1.9f, 0);
                        Vector3 HeadPosition = WorldToScreenPoint(camera, HeadPos);
                        if (HeadPosition.z < 1) continue;

                        draw->AddCircle(ImVec2(screenWidth / 2, screenHeight / 2), Fov_Aim, ImColor(255, 255, 255), 0, 1.5f);


                        float distance = Vector3::Distance(getPosition(local_player), Toepos);
                        float Height = abs(HeadPosition.y - Toeposi.y) * (1.2 / 1.1);
                        float Width = Height * 0.50f;
                        
                        Rect rect = Rect(HeadPosition.x - Width / 2.f, screenHeight - HeadPosition.y, Width, Height);


              if (Mass.Sucks) {
    if (closestEnemy != NULL && local_player != NULL && closestEnemy != local_player && !get_IsDieing(closestEnemy)) {
        void* playerTransform = Component_GetTransform(local_player);
        void* enemyTransform  = Component_GetTransform(closestEnemy);

        if (playerTransform != NULL && enemyTransform != NULL) {
            Vector3 LocalPlayerPos = Transform_GetPosition(playerTransform);
            Vector3 EnemyPos       = Transform_GetPosition(enemyTransform);

            float distance = Vector3::Distance(LocalPlayerPos, EnemyPos);

            if (distance <= Mass.Sucks1) {
                Vector3 forward = GetForward(playerTransform);
                Vector3 newPos  = LocalPlayerPos + (forward * Mass.FrontOffset);

                // Optional: Validate newPos sanity
                if (isfinite(newPos.x) && isfinite(newPos.y) && isfinite(newPos.z)) {
                    Transform_INTERNAL_SetPosition(enemyTransform, Vvector3(newPos.x, newPos.y, newPos.z));
                }
            }
        }
    }
}
/*
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
*/

                          if (Config.ESP.Line) {
                            if(showline == 0) {
                                if (get_IsDieing(closestEnemy)) {
                                    draw->AddLine(ImVec2(screenWidth / 2, 80), ImVec2(rect.x + rect.w / 2, rect.y + rect.h / 35), IM_COL32(Color.line2[0] * 255.0f, Color.line2[1] * 255.0f, Color.line2[2] * 255.0f, Color.line2[3] * 255.0f), 2.0);
                                } else {
                                    draw->AddLine(ImVec2(screenWidth / 2, 80), ImVec2(rect.x + rect.w / 2, rect.y + rect.h / 35), IM_COL32(Color.line1[0] * 255.0f, Color.line1[1] * 255.0f, Color.line1[2] * 255.0f, Color.line1[3] * 255.0f), 2.0);
                                }
                            } else if(showline1) {
                                if (get_IsDieing(closestEnemy)) {
                                    draw->AddLine(ImVec2(screenWidth / 2, screenHeight / 2), ImVec2(rect.x + rect.w / 2, rect.y + rect.h / 35), IM_COL32(Color.line2[0] * 255.0f, Color.line2[1] * 255.0f, Color.line2[2] * 255.0f, Color.line2[3] * 255.0f), 2.0);
                                } else {
                                    draw->AddLine(ImVec2(screenWidth / 2, screenHeight / 2), ImVec2(rect.x + rect.w / 2, rect.y + rect.h / 35), IM_COL32(Color.line1[0] * 255.0f, Color.line1[1] * 255.0f, Color.line1[2] * 255.0f, Color.line1[3] * 255.0f), 2.0);
                                }
                            } else if(showline2) {
                                if (get_IsDieing(closestEnemy)) {
                                    draw->AddLine(ImVec2(screenWidth / 2, screenHeight), ImVec2(rect.x + rect.w / 2, rect.y + rect.h / 35), IM_COL32(Color.line2[0] * 255.0f, Color.line2[1] * 255.0f, Color.line2[2] * 255.0f, Color.line2[3] * 255.0f), 2.0);
                                } else {
                                    draw->AddLine(ImVec2(screenWidth / 2, screenHeight), ImVec2(rect.x + rect.w / 2, rect.y + rect.h / 35), IM_COL32(Color.line1[0] * 255.0f, Color.line1[1] * 255.0f, Color.line1[2] * 255.0f, Color.line1[3] * 255.0f), 2.0);
                                }
                            }
                        }
						

                   if (Config.ESP.Box) {
    int x = rect.x;
    int y = rect.y;
    draw->AddRect(ImVec2(x, y), ImVec2(x + rect.w, y + rect.h), IM_COL32(Color.box[0] * 255.0f, Color.box[1] * 255.0f, Color.box[2] * 255.0f, Color.box[3] * 255.0f), 1.0f, 0, 2.0f);
}
  if (Config.ESP.Target) { 
                            if (get_IsDieing(closestEnemy)) {            
                                if (Config.ESP.Target) {  
                                    int xx = rect.x + rect.w + 2;
                                    int yy = rect.y;
                                    draw->AddRectFilled(ImVec2(xx, yy), ImVec2(xx + 5, yy + rect.h), ImColor(0, 0, 0, 255));        
                                    draw->AddRectFilled(ImVec2(xx + 1, yy + rect.h - (rect.h * ((float)GetHp(closestEnemy) / get_MaxHP(closestEnemy)))), ImVec2(xx + 4, yy + rect.h),die);      
                                }
                            }else {
                                long clr = ImColor(0,255,0,255);   

                                if (GetHp(closestEnemy) <= (get_MaxHP(closestEnemy) * 0.6)) {
                                    clr = ImColor(255, 255, 0, 255);
                                }

                                if (GetHp(closestEnemy) < (get_MaxHP(closestEnemy) * 0.3)) {
                                    clr = ImColor(255, 0, 0, 255);
                                }

                                int xx = rect.x + rect.w + 2;
                                int yy = rect.y;
                                draw->AddRectFilled(ImVec2(xx, yy), ImVec2(xx + 5, yy + rect.h), ImColor(0, 0, 0, 255));        
                                draw->AddRectFilled(ImVec2(xx + 1, yy + rect.h - (rect.h * ((float)GetHp(closestEnemy) / get_MaxHP(closestEnemy)))), ImVec2(xx + 4, yy + rect.h),clr);                       
                            }

    // Health Bar (keep your original logic for dying state)
         if (Config.ESP.Health) {
                            monoString* Nick = get_NickName(closestEnemy);
                            std::string names;

                            if(Nick != NULL) {
                                int nick_Len = Nick ->getLength();
                                for(int i = 0; i < nick_Len; i++) {
                                    char data = get_Chars(Nick, i);
                                    names += isascii(data) ? data : '?';
                                }
                            }

                            std::string nickname3;
                            nickname3 += "";               
                            nickname3 += "[";
                            nickname3 += int_to_string((int)distance).c_str();
                            nickname3 += "] ";
                            nickname3 += names;
                            
                            if (get_IsDieing(closestEnemy)) {
                                ImVec2 nicksize = ImGui::CalcTextSize(nickname3.c_str());
                                
                                ImVec2 text_pos = ImVec2(rect.x + (rect.w / 2) - (nicksize.x / 2), rect.y - nicksize.y);
                                ImVec2 rect_min = ImVec2(text_pos.x - 2, text_pos.y - 2);
                                ImVec2 rect_max = ImVec2(text_pos.x + nicksize.x + 2, text_pos.y + nicksize.y + 2);
                                draw->AddRectFilled(rect_min, rect_max, IM_COL32(255, 255, 255, 255));
                                draw->AddRect(rect_min, rect_max, IM_COL32(Color.info2[0] * 255.0f, Color.info2[1] * 255.0f, Color.info2[2] * 255.0f, Color.info2[3] * 255.0f));
                                draw->AddText(text_pos, IM_COL32(Color.info2[0] * 255.0f, Color.info2[1] * 255.0f, Color.info2[2] * 255.0f, Color.info2[3] * 255.0f), nickname3.c_str());
                            } else {
                                ImVec2 nicksize = ImGui::CalcTextSize(nickname3.c_str());
                                
                                ImVec2 text_pos = ImVec2(rect.x + (rect.w / 2) - (nicksize.x / 2), rect.y - nicksize.y);
                                ImVec2 rect_min = ImVec2(text_pos.x - 2, text_pos.y - 2);
                                ImVec2 rect_max = ImVec2(text_pos.x + nicksize.x + 2, text_pos.y + nicksize.y + 2);
                                draw->AddRectFilled(rect_min, rect_max, IM_COL32(255, 255, 255, 255));
                                draw->AddRect(rect_min, rect_max, IM_COL32(Color.info1[0] * 255.0f, Color.info1[1] * 255.0f, Color.info1[2] * 255.0f, Color.info1[3] * 255.0f));
                                draw->AddText(text_pos, IM_COL32(Color.info1[0] * 255.0f, Color.info1[1] * 255.0f, Color.info1[2] * 255.0f, Color.info1[3] * 255.0f), nickname3.c_str());
                            }

}

//}
/*
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
*/
                      
if (totalEnemies >= 0) {
    std::string enemyText = (totalEnemies > 0) ? std::to_string(totalEnemies) : "";

    float fontSize = 40.0f;
    ImFont* font = ImGui::GetFont();
    ImVec2 textSize = font->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, enemyText.c_str());

    ImVec2 center(screenWidth * 0.5f, 50.0f);
    ImVec2 textPos(center.x - textSize.x * 0.5f, center.y - textSize.y * 0.5f);

    ImColor outlineColor(0, 0, 0, 255);
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0)
                draw->AddText(font, fontSize, ImVec2(textPos.x + dx, textPos.y + dy), outlineColor, enemyText.c_str());
        }
    }

    ImColor textColor = (totalEnemies > 0) ? ImColor(255, 50, 50, 255) : ImColor(0, 255, 0, 255);
    draw->AddText(font, fontSize, textPos, textColor, enemyText.c_str());

    
    std::string credit = "";
    float creditFontSize = 20.0f; 

    ImVec2 creditSize = font->CalcTextSizeA(creditFontSize, FLT_MAX, 0.0f, credit.c_str());
    ImVec2 creditPos(screenWidth * 0.5f - creditSize.x * 0.5f, screenHeight - 30.0f);

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0)
                draw->AddText(font, creditFontSize, ImVec2(creditPos.x + dx, creditPos.y + dy), ImColor(0, 0, 0, 255), credit.c_str());
        }
    }

    draw->AddText(font, creditFontSize, creditPos, ImColor(255, 255, 255, 255), credit.c_str());
}
                        }
                    }
                }
           
    }
}
}}




bool (*IsFoldWingGliding)(void *player);
bool _IsFoldWingGliding(void *player) {
    if (player != NULL) {
        if(Enable) {
            if (speedrun) {
                return true;
            }
        }
    }
    return IsFoldWingGliding(player);
}

static int (*MappingFromPhysXState)(...);
static int _MappingFromPhysXState(void* state) {
 if(Enable) {
     if (speedrun) {
      return 1;
     }
    }
 return MappingFromPhysXState(state);
}
    /*
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
*/

/*



bool (*get_maxKillSpeed)(void *thiz);
bool _get_maxKillSpeed(void *thiz) {
    if (thiz != NULL) {
        if(Enable) {
            if (fastKill) {
                return true;
            }
        }
    }
    return get_maxKillSpeed(thiz);
}*/



float (*get_maxKillSpeed)(void *thiz);
float _get_maxKillSpeed(void *thiz) {
    if (thiz != NULL && Enable) {
        return maxKillSpeed;
    }
    return get_maxKillSpeed(thiz);
}






bool (*GetCombineType)(void *thiz);
bool _GetCombineType(void *thiz) {
    if (thiz != NULL) {
        if(Enable) {
            if (DoubleGun) {
                return true;
            }
        }
    }
    return _GetCombineType(thiz);
}

bool (*get_IsGod)(void *thiz);
bool _get_IsGod(void *thiz) {
    if (thiz != NULL) {
        if(Enable) {
            if (GoldenAll) {
                return true;
            }
        }
    }
    return _get_IsGod(thiz);
}

bool (*get_InSwapWeaponCD)(void* thiz);
bool _get_InSwapWeaponCD(void* thiz) {
  if (fastswitch) {
        return false;
    }
    return get_InSwapWeaponCD(thiz);
}



bool(*_ResetGuest)(void* _this);
bool ResetGuest(void* _this){
    if (_this != NULL) {
        if (Reset) {
            return true; 
            remove(OBFUSCATE("/storage/emulated/0/com.garena.msdk/guest100067.dat"));
        }
    }
}/*
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================

===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
===============================[ 𝗠𝗔𝗗𝗘 𝗕𝗬 @𝗶𝘁𝘀𝗔𝘅𝗹𝗢𝗽 ]============================
*/
