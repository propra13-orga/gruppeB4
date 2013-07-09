#include <WinSock2.h>
#include <Windows.h>
#include <iostream>


	#include <windows.h>

#include <winsock2.h>

#include <stdio.h>

//Prototypen

int startWinsock(void);



int main(int argc, char ** argv)
{

  long rc;

  SOCKET acceptSocket;
  SOCKET connectedSocket;

  SOCKADDR_IN addr;

  // Winsock starten

  rc=startWinsock();

  if(rc!=0)

  {

    printf("Fehler: startWinsock, fehler code: %d\n",rc);

    return 1;

  }

  else

  {

    printf("Winsock gestartet!\n");

  }

  // Socket erstellen

  acceptSocket=socket(AF_INET,SOCK_STREAM,0);

  if(acceptSocket==INVALID_SOCKET)

  {

    printf("Fehler: Der Socket konnte nicht erstellt werden, fehler code: %d\n",WSAGetLastError());

    return 1;

  }

  else

  {

    printf("Socket erstellt!\n");

  }

  memset(&addr,0,sizeof(SOCKADDR_IN));

addr.sin_family=AF_INET;

addr.sin_port=htons(12345);

addr.sin_addr.s_addr=ADDR_ANY;

rc=bind(acceptSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR_IN));

if(rc==SOCKET_ERROR)

{

  printf("Fehler: bind, fehler code: %d\n",WSAGetLastError());

  return 1;

}

else

{

  printf("Socket an port 12345 gebunden\n");

}

rc=listen(acceptSocket,10);

if(rc==SOCKET_ERROR)

{

  printf("Fehler: listen, fehler code: %d\n",WSAGetLastError());

  return 1;

}

else

{

  printf("acceptSocket ist im listen Modus....\n"); 

}




connectedSocket=accept(acceptSocket,NULL,NULL);

if(connectedSocket==INVALID_SOCKET)

{

  printf("Fehler: accept, fehler code: %d\n",WSAGetLastError());

  return 1;

}

else

{

  printf("Neue Verbindung wurde akzeptiert!\n");

}

system("PAUSE");

  return 0;

}





int startWinsock(void)

{

  WSADATA wsa;

  return WSAStartup(MAKEWORD(2,0),&wsa);

}
