#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512 // 수신 버퍼 크기
#define DEFAULT_PORT "27015" // 사용할 포트 번호 선언

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

    // 접속할 주소 정보를 명령 인수로 추가했는지 여부 채크
    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        system("pause");
        return 1;
    }

    // Initialize Winsock
    // WSAStartup : WS2_32.dll 사용을 시작
    // MAKEWORD(2, 2) : Winsock 버전 2.2를 요청
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        system("pause");
        return 1;
    }

    // ***** 클라이언트에 대한 소켓 만들기 ***** //
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;

    ZeroMemory(&hints, sizeof(hints));
    // AF_UNSPEC : IPv4 또는 IPv6와 같은 특정한 주소 체계를 선택할 필요 없이 시스템이 사용 가능한 모든 주소 체계를 자동으로 선택
    hints.ai_family = AF_UNSPEC;
    // SOCK_STREAM : 스트림 소켓을 지정
    hints.ai_socktype = SOCK_STREAM;
    // IPPROTO_TCP : TCP 프로토콜 을 지정
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    // getaddrinfo : IP, port를 이용하여 네트워크 주소 정보를 가져오는 데 사용
    // argv[1] : 명령 인수로 추가한 주소 정보
    // &hints : 가져올 주소에 대한 힌트 제공
    // &result : 가져온 주소 정보를 저장
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        system("pause");
        return 1;
    }

    // 클라이언트 연결 대기 socket
    SOCKET ConnectSocket = INVALID_SOCKET;

    // result에 반환되는 주소가 여러개가 될수 있다
    // 예를 들어, 로드 밸런싱이나 장애 조치를 위해 여러개의 IP를 사용할 수 있다.
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

    freeaddrinfo(result);// bind 함수가 호출되면 getaddrinfo 함수에서 반환된 주소 정보가 더 이상 필요하지 않습니다. 

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        system("pause");
        return 1;
    }

    // ***** 클라이언트에서 데이터 보내기 및 받기 ***** //
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