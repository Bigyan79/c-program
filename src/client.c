#include <stdio.h>
#include <winsock2.h>

int main()
{
    struct WSAData wsaData;

    // Initialize WinSock API
    if (WSAStartup(MAKEWORD(2, 2), &wsaData != 0))
    {
        printf("Failed to error");
        return 1;
    }
    return 0;
}
