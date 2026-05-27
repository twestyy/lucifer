//
// Created by xanax on 27/5/2026.
//
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H


class Client {
private:
    SOCKET sock;

public:
    Client();
    ~Client();
    int connection(std::string ip, int port);

};


#endif //CLIENT_CLIENT_H
