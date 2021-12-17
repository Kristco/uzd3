cmake_minimum_required(VERSION 3.20)
project(uzd1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(uzd1
        main.cpp vector/strukturos.h vector/skaiciavimai.cpp vector/skaiciavimai.h vector/duomenu_apdorojimas.cpp vector/duomenu_apdorojimas.h klases/klases.h klases/klases.cpp klases/klases_duomenu_apdorojimas.h klases/klases_duomenu_apdorojimas.cpp)
