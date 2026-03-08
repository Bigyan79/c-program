#include <stdio.h>
#include <winsock2.h>

int main()
{
    struct WSAData wsaData;

    // Initialize WinSock API
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Failed to startup WSA\n");
        return 1;
    }

    // Create a Socket
    SOCKET _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    return 0;
}