cmake_minimum_required(VERSION 3.28)
project(Demo1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Demo1 main.c
        my_bio.c
        my_bio.h)
