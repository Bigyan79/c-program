#define _WIN32_WINNT 0x0601
#include <string.h>
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

WINSOCK_API_LINKAGE const char *WSAAPI inet_ntop(int af, const void *src, char *dst, size_t size);

int main(int argc, char *argv[])
{
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("WSAStartup failed\n");
        return 1;
    }
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, "3490", &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    bind(sockfd, res->ai_addr, res->ai_addrlen);

    WSACleanup();
    return 0;
}
