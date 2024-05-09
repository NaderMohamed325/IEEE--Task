cmake_minimum_required(VERSION 3.28)
project(Project C)

set(CMAKE_C_STANDARD 23)

add_executable(Project main.c
        Client.h
        Client.c)
