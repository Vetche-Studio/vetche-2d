cmake_minimum_required(VERSION 3.5.0)
project(Turbo-Trooper VERSION 0.1.0 LANGUAGES C CXX)

include_directories(
    ${PROJECT_NAME}
    ../../src
    .)

set(BRAINDUST_PLATFORM "NINTENDO_DS")

add_subdirectory(../../ ./bin)

add_brain_dust_game(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)