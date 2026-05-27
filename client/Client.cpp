//
// Created by xanax on 27/5/2026.
//
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "Client.h"
#pragma comment(lib, "ws2_32.lib")


SOCKET intializeSocket() {
   SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock == INVALID_SOCKET) {
      std::cout<<"Error creating socket"<<WSAGetLastError()<<std::endl;

      WSACleanup();
      return INVALID_SOCKET;

    } else {
      std::cout<<"Socket created"<<std::endl;
    }
  return sock;
}

Client::Client() {
  sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (sock == INVALID_SOCKET) {
    std::cout << "Socket creation failed: " << WSAGetLastError() << std::endl;
  // } else {
  //   std::cout << "Socket created" << std::endl;
  }
}
Client::~Client() {
  if (sock != INVALID_SOCKET) {
    closesocket(sock);
  }
}

int Client::connection(std::string ip, int port) {

  if (sock == INVALID_SOCKET) {
    return 1;
  }

  sockaddr_in serverInfo;
  ZeroMemory(&serverInfo, sizeof(serverInfo));

  serverInfo.sin_family = AF_INET;
  serverInfo.sin_port = htons(port);

  inet_pton(AF_INET, ip.c_str(), &serverInfo.sin_addr);

  int result = connect(sock, (sockaddr*)&serverInfo, sizeof(serverInfo));

  if (result == SOCKET_ERROR) {
    std::cout << "Connection failed: " << WSAGetLastError() << std::endl;
    return 1;
  }

  std::cout << "Connected successfully" << std::endl;
  return 0;
}