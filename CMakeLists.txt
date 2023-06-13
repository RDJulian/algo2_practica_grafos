cmake_minimum_required(VERSION 3.26)
project(algo2_practica_grafos)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Werror -Wconversion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")
set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)
include_directories(src)

add_executable(algo2_practica_grafos
        src/Grafo.cpp
        src/CaminoDD2.cpp
        src/Camino.cpp
        src/Lector.cpp
        src/Matriz.cpp
        main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "programa.exe")