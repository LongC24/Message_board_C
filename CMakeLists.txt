cmake_minimum_required(VERSION 3.23)
project(Message_board)

set(CMAKE_CXX_STANDARD 17)

add_executable(Message_board  main.cpp Network.h Network.cpp User.cpp User.h)
