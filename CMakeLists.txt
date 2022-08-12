cmake_minimum_required(VERSION 3.16)
project(Ass_Two_Client)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Ass_Two_Client
        client.cpp
        client.h
        fileClientHandler.cpp
        fileClientHandler.h
        main.cpp)
