cmake_minimum_required(VERSION 3.20)
project(client)

set(CMAKE_CXX_STANDARD 20)

add_executable(client
        main.cpp
        Connect.cpp
        Connect.h
)

# Asio header-only
target_compile_definitions(client PRIVATE ASIO_STANDALONE)

target_include_directories(client PRIVATE ${CMAKE_SOURCE_DIR}/asio/asio/include)
target_link_libraries(client PRIVATE ws2_32)
#add_compile_definitions(_WIN32_WINNT=0x0601)