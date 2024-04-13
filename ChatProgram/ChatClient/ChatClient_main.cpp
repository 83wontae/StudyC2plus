#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512 // ���� ���� ũ��
#define DEFAULT_PORT "27015" // ����� ��Ʈ ��ȣ ����

void receiveMessage(SOCKET client)
{
    char buffer[DEFAULT_BUFLEN];

    while (true)
    {
        int bytesReceived = recv(client, buffer, DEFAULT_BUFLEN, 0);

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

int __cdecl main(int argc, char** argv)
{
    WSADATA wsaData;

    int iResult;

    // ������ �ּ� ������ ��� �μ��� �߰��ߴ��� ���� äũ
    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        system("pause");
        return 1;
    }

    // Initialize Winsock
    // WSAStartup : WS2_32.dll ����� ����
    // MAKEWORD(2, 2) : Winsock ���� 2.2�� ��û
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        system("pause");
        return 1;
    }

    // ***** Ŭ���̾�Ʈ�� ���� ���� ����� ***** //
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;

    ZeroMemory(&hints, sizeof(hints));
    // AF_UNSPEC : IPv4 �Ǵ� IPv6�� ���� Ư���� �ּ� ü�踦 ������ �ʿ� ���� �ý����� ��� ������ ��� �ּ� ü�踦 �ڵ����� ����
    hints.ai_family = AF_UNSPEC;
    // SOCK_STREAM : ��Ʈ�� ������ ����
    hints.ai_socktype = SOCK_STREAM;
    // IPPROTO_TCP : TCP �������� �� ����
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    // getaddrinfo : IP, port�� �̿��Ͽ� ��Ʈ��ũ �ּ� ������ �������� �� ���
    // argv[1] : ��� �μ��� �߰��� �ּ� ����
    // &hints : ������ �ּҿ� ���� ��Ʈ ����
    // &result : ������ �ּ� ������ ����
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        system("pause");
        return 1;
    }

    // Ŭ���̾�Ʈ ���� ��� socket
    SOCKET ConnectSocket = INVALID_SOCKET;

    // result�� ��ȯ�Ǵ� �ּҰ� �������� �ɼ� �ִ�
    // ���� ���, �ε� �뷱���̳� ��� ��ġ�� ���� �������� IP�� ����� �� �ִ�.
    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);

        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            system("pause");
            return 1;
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }

        std::cout << "Connected to the chat server" << std::endl;
        break;
    }

    freeaddrinfo(result);// bind �Լ��� ȣ��Ǹ� getaddrinfo �Լ����� ��ȯ�� �ּ� ������ �� �̻� �ʿ����� �ʽ��ϴ�. 

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        system("pause");
        return 1;
    }

    // ***** Ŭ���̾�Ʈ���� ������ ������ �� �ޱ� ***** //
    const char* sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    std::thread receiveThread(receiveMessage, ConnectSocket);

    while (true)
    {
        std::cin.getline(recvbuf, DEFAULT_BUFLEN);

        if (strlen(recvbuf) > 0)
        {
            send(ConnectSocket, recvbuf, strlen(recvbuf), 0);
        }
    }

    receiveThread.join();
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}