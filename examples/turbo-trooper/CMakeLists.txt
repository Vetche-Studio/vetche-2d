cmake_minimum_required(VERSION 3.5.0)
project(Turbo-Trooper VERSION 0.1.0 LANGUAGES C CXX)
set(PROJECT_TARGET_NAME ${PROJECT_NAME})

include_directories(
    ${PROJECT_TARGET_NAME}
    ../../src
    .)


set(BRAINDUST_PLATFORM "PLAYDATE")
add_subdirectory(../../ ./bin)



add_brain_dust_toolbox_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)