cmake_minimum_required(VERSION 3.24)
project(Tree_Sruct C)

set(CMAKE_C_STANDARD 11)

add_executable(Tree_Sruct main.c levelorder_queue.cpp)
