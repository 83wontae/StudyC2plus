#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <mutex>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512 // 수신 버퍼 크기
#define DEFAULT_PORT "27015" // 사용할 포트 번호 선언

const int MAX_CLIENT = 10;

int clientCount = 0;
SOCKET clients[MAX_CLIENT];
std::mutex mtx;

void broadcastMessage(const char* message, int sender)
{
    mtx.lock();

    for (int i = 0; i < clientCount; i++)
    {
        if (i != sender)
        {
            send(clients[i], message, DEFAULT_BUFLEN, 0);
        }
    }

    mtx.unlock();
}

void clientHandler(int idx)
{
    char buffer[DEFAULT_BUFLEN];

    while (true)
    {
        int bytesReceived = recv(clients[idx], buffer, DEFAULT_BUFLEN, 0);

        if (bytesReceived <= 0)
        {
            mtx.lock();

            closesocket(clients[idx]);
            clientCount--;

            for (int i = idx; i < clientCount; i++)
            {
                clients[i] = clients[i + 1];
            }

            mtx.unlock();

            std::cout << "Client disconnected" << std::endl;
            break;
        }

        buffer[bytesReceived] = '\0';
        broadcastMessage(buffer, idx);
    }
}

int __cdecl main(void)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for the server to listen for client connections.
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, MAX_CLIENT);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Chat server started on port " << DEFAULT_PORT << std::endl;

    while (true)
    {
        // Accept a client socket
        SOCKET ClientSocket = accept(ListenSocket, NULL, NULL);

        if (clientCount < MAX_CLIENT)
        {
            mtx.lock();

            clients[clientCount++] = ClientSocket;

            mtx.unlock();

            std::cout << "Client connected" << std::endl;
            std::thread(clientHandler, clientCount - 1).detach();
        }
        else
        {
            closesocket(ClientSocket);
        }
    }

    WSACleanup();

    return 0;
}