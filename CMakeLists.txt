cmake_minimum_required(VERSION 3.20)
project(uzd1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(uzd1
        main.cpp klases/klases.h klases/klases.cpp klases/klases_duomenu_apdorojimas.h klases/klases_duomenu_apdorojimas.cpp)

add_executable(main main.cpp)

set(CMAKE_EXE_LINKER_FLAGS -static)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static-libgcc -static-libstdc++ -static")
set(CMAKE_EXE_LINKER_FLAGS=-static-libgcc -static-libstdc++ -static)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s -O3")

