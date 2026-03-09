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

    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    if (argc != 2)
    {
        fprintf(stderr, "usage: showip hostname\n");
        return 1;
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP address for %s: \n\n", argv[1]);

    for (p = res; p != NULL; p = p->ai_next)
    {
        void *addr;
        char *ipver;
        struct sockaddr_in *ipv4;
        struct sockaddr_in6 *ipv6;

        if (p->ai_family == AF_INET)
        {
            ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPV4";
        }
        else
        {
            ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPV6";
        }

        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("%s:%s\n", ipver, ipstr);
    }
    freeaddrinfo(res);
    WSACleanup();
    return 0;
}