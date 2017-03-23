cmake_minimum_required(VERSION 3.6)
project(app)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c buffer.c buffer.h ordenamiento.c ordenamiento.h wordlist.c wordlist.h)
add_executable(app ${SOURCE_FILES})