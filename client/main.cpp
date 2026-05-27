#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "Client.h"
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);



    std::string ip = "127.0.0.1";
    int port = 65;
    Client client;
    client.connection(ip, port); 


}