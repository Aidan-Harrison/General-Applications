#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

int main() {
	/* Winsock */
	WSADATA wsData;
	WORD version = MAKEWORD(2, 2);

	int wsOK = WSAStartup(version, &wsData);
	if (wsOK != 0) {
		std::cerr << "Failed to initialise winsock!\n";
		exit(1);
	}

	/* Socket */
	// SOCK_STREAM = TCP
	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET) {
		std::cout << "Failed to create socket!\n";
		exit(1);
	}

	/* IP & Port*/
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000); // 'htons' = Host To Network Short
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // Any address

	bind(listenSocket, (sockaddr*)&hint, sizeof(hint));

	listen(listenSocket, SOMAXCONN); // Listen for a maximum of total 15 connections as a backlog (SOMAXCONN) 

	/* Wait for connection */
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listenSocket, (sockaddr*)&client, &clientSize);
	if (clientSocket == INVALID_SOCKET) {
		std::cerr << "Client failed to connect to socket!\n";
		exit(1);
	}

	char host[NI_MAXHOST];    // Client name
	char service[NI_MAXSERV]; // Port client is on

	memset(host, 0, NI_MAXHOST);
	memset(service, 0, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
		std::cout << host << "on port" << service << '\n';
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << "on port" << ntohs(client.sin_port) << '\n'; // Network To Host Short
	}

	// connected successfully, no longer need socket
	closesocket(listenSocket);

	// OpenGL
	while (true) {
		// Wait for server input and GlTexture creation
		
		// Echo GLTexture to client
	}

	return 0;
}