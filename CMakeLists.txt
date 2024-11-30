cmake_minimum_required(VERSION 3.29)
project(c_linkedlist C)

set(CMAKE_C_STANDARD 11)

add_executable(c_linkedlist main.c
        linkedlist.c
        linkedlist.h)
