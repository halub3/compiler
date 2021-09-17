cmake_minimum_required(VERSION 3.20)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c bfs/bfs.c bfs/bfs.h headers/structs.h lib/data.c headers/data.h headers/big_include.h lib/launch.c headers/launch.h)
