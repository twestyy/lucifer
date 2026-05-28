//
// Created by xanax on 27/5/2026.
//

#include <iostream>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include "Connect.h"


#define ASIO_STANDALONE



void connection() {


    asio::error_code ec;
    asio:asio::io_context context;
    asio::ip::tcp::endpoint endpoint(
    asio::ip::make_address("127.0.0.1", ec),
    50
);


    asio::ip::tcp::socket socket(context);
    socket.connect(endpoint,ec);
    if (!ec) {
        std::cout <<"connected"<< std::endl;

    } else {
        std::cout <<ec.message()<< std::endl;
    }

    if (socket.is_open()) {
        std::string request;
    }




    system("pause");
}

int main() {
    connection();
    return 0;
}