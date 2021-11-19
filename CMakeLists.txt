cmake_minimum_required(VERSION 3.20)
project(uzd1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(uzd1
        main.cpp list/strukturos.h list/skaiciavimai.cpp list/skaiciavimai.h list/failu_tvarkymas.cpp list/failu_tvarkymas.h list/duomenu_apdorojimas.cpp list/duomenu_apdorojimas.h
        vector/strukturos_vector.h vector/skaiciavimai_vector.cpp vector/skaiciavimai_vector.h vector/failu_tvarkymas_vector.cpp vector/failu_tvarkymas_vector.h vector/duomenu_apdorojimas_vector.cpp vector/duomenu_apdorojimas_vector.h)
