
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <winsock.h>
int startWinsock()
{
    WSAData wsa;
    return WSAStartup(MAKEWORD(2,0),&wsa);
}
int main(int argc, char ** argv)
{
    long rc;
    SOCKET s;
    SOCKADDR_IN addr;
    rc = startWinsock();
    if(rc!=0)
    {
        std::cout << "Fehler: startWinsock, fehler code: %d\n",rc;
        return 1;
    }
    else
    {
        std::cout << "Winsock gestartet" << std::endl;
    }
    s = socket(AF_INET,SOCK_STREAM,0);
    if(s== INVALID_SOCKET)
    {
        std::cout << "Fehlernummer: " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "Socket gestartet" << std::endl;
    }
    memset(&addr,0,sizeof(SOCKADDR));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5050);
    addr.sin_addr.s_addr = inet_addr("25.193.46.75");
    rc = connect(s,(SOCKADDR*)&addr,sizeof(SOCKADDR));
    if(rc == SOCKET_ERROR)
    {
        std::cout << "Error, Verbindung gescheitert!: " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "Verbunden mit 10.0.0.6" << std::endl;
    }
    system("PAUSE");
    return 0;
    
}
   
