cmake_minimum_required(VERSION 3.16)
project(Ass_Two_Client)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(AssTwoClient.out
        client/client.cpp
        client/client.h
        client/fileClientHandler.cpp
        client/fileClientHandler.h
        main.cpp)
