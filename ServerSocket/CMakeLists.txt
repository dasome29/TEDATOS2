cmake_minimum_required(VERSION 3.15)
project(ServerSocket)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServerSocket main.cpp LinkedList.hpp Graph.hpp test.hpp Matrix.h Dijkstra.hpp)