cmake_minimum_required(VERSION 3.20)
project(uzd1)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(uzd1
        ../main.cpp strukturos.h skaiciavimai.cpp skaiciavimai.h failu_tvarkymas.cpp failu_tvarkymas.h duomenu_apdorojimas.cpp duomenu_apdorojimas.h)