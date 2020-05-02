cmake_minimum_required(VERSION 3.16)
project(c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c
        FixedCircularBuffer.c
        FixedCircularBuffer.h
        main.c)
