#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>

#pragma comment(lib, "Ws2_32.lib")

const int BUF_SIZE = 1024;
const int PORT = 12345;

void receiveMessage(SOCKET client)
{
    char buffer[BUF_SIZE];

    while (true)
    {
        int bytesReceived = recv(client, buffer, BUF_SIZE, 0);

        if (bytesReceived > 0)
        {
            //buffer[bytesReceived] = '\0';
            std::cout << buffer << std::endl;
        }
        else
        {
            break;
        }
    }

    std::cout << "Disconnected from the chat server" << std::endl;
}

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &clientAddr.sin_addr);
    clientAddr.sin_port = htons(PORT);

    connect(client, (sockaddr*)&clientAddr, sizeof(clientAddr));

    std::cout << "Connected to the chat server" << std::endl;

    std::thread receiveThread(receiveMessage, client);

    char buffer[BUF_SIZE];

    while (true)
    {
        std::cin.getline(buffer, BUF_SIZE);

        if (strlen(buffer) > 0)
        {
            send(client, buffer, strlen(buffer), 0);
        }
    }

    receiveThread.join();
    closesocket(client);
    WSACleanup();

    return 0;
}