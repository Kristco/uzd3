cmake_minimum_required(VERSION 3.20)
project(uzd1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(uzd1
        main.cpp strukturos.h skaiciavimai.h skaiciavimai.cpp duomenu_operacijos.h duomenu_operacijos.cpp)
