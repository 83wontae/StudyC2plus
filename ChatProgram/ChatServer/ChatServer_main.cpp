#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <mutex>

#pragma comment(lib, "Ws2_32.lib")

const int BUF_SIZE = 1024;
const int MAX_CLIENT = 10;
const int PORT = 12345;

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
            send(clients[i], message, BUF_SIZE, 0);
        }
    }

    mtx.unlock();
}

void clientHandler(int idx)
{
    char buffer[BUF_SIZE];

    while (true)
    {
        int bytesReceived = recv(clients[idx], buffer, BUF_SIZE, 0);

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

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    bind(server, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(server, MAX_CLIENT);

    std::cout << "Chat server started on port " << PORT << std::endl;

    while (true)
    {
        SOCKET client = accept(server, NULL, NULL);

        if (clientCount < MAX_CLIENT)
        {
            mtx.lock();

            clients[clientCount++] = client;

            mtx.unlock();

            std::cout << "Client connected" << std::endl;
            std::thread(clientHandler, clientCount - 1).detach();
        }
        else
        {
            closesocket(client);
        }
    }

    WSACleanup();

    return 0;
}