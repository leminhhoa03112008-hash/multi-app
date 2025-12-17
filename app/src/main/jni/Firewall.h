#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <dlfcn.h>

int blockcount = 0;
bool block_connections = true;

// Original connect function pointer
int (*original_connect)(int, const struct sockaddr *, socklen_t);

// Custom connect function to hook into libc.so
int my_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    char ip[INET_ADDRSTRLEN];

    if (addr->sa_family == AF_INET) {
        struct sockaddr_in *addr_in = (struct sockaddr_in *)addr;
        inet_ntop(AF_INET, &addr_in->sin_addr, ip, sizeof(ip));

        // Check blocked IPs if block_connections is enabled
        if (block_connections &&
            (strcmp(ip, "192.168.1.1") == 0 ||
             strcmp(ip, "192.981.18.1") == 0 ||
             strcmp(ip, "1.20.541.128") == 0)) {
            printf("Connection to %s blocked\n", ip);
            blockcount++;
            return -1; // Block connection
        }
    }

    // Check blocked hostnames if block_connections is enabled
    struct hostent *host = gethostbyaddr(&(((struct sockaddr_in*)addr)->sin_addr), sizeof(struct in_addr), AF_INET);
    if (block_connections && host && 
        (strcmp(host->h_name, OBFUSCATE("dl.gmc.freefiremobile.com")) == 0 ||
		  strcmp(host->h_name, OBFUSCATE("gin.freefiremobile.com")) == 0 ||
		  strcmp(host->h_name, OBFUSCATE("gin.freefireind.in")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("ff.dr.grtc.garenanow.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("dl.ctlin.freefiremobile.com")) == 0 ||
         strcmp(host->h_name, "dl.cvs.freefiremobile.com") == 0)) {
        printf("Connection to %s blocked\n", host->h_name);
        blockcount++;
        return -1; // Block connection
    }

    return original_connect(sockfd, addr, addrlen);
}

__attribute__((constructor))
void hook_connect() {
    // Hook the connect function
	/*
    void *connect_addr = DobbySymbolResolver("/system/lib/libc.so", "connect");
    
   if (connect_addr) {
        DobbyHook(connect_addr, (void *)my_connect, (void **)&original_connect);
    } else {
        fprintf(stderr, "Failed to hook connect function: %s\n", dlerror());
    }
	*/
}

