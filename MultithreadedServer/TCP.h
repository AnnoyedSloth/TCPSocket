#pragma once
#include<WinSock2.h>
#include<stdlib.h>
#include<stdio.h>

#define SERVERPORT 9000
#define BUFSIZE 512

class TCP {
	int retval;
	WSADATA wsa;
	SOCKET listen_sock;
	SOCKADDR_IN serveraddr;

	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen;
	HANDLE hThread;
	
public:
	TCP();
	~TCP();

	void Loop();
	DWORD WINAPI ProcessClient(LPVOID arg);
	void err_quit(char *msg);
	void err_display(char *msg);
};