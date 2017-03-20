cmake_minimum_required(VERSION 3.6)
project(app)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Lista.h Lista.c wordlist.c wordlist.h)
add_executable(app ${SOURCE_FILES})