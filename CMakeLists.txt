cmake_minimum_required(VERSION 3.15)
project(vetche-2d-sandbox CXX)

find_package(raylib REQUIRED)
find_package(Angelscript REQUIRED)

add_executable(vetche-2d-sandbox src/main.cpp)

target_link_libraries(vetche-2d-sandbox raylib Angelscript::angelscript)