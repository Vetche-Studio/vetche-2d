cmake_minimum_required(VERSION 3.5.0)
project(BrainDust-Toolbox VERSION 0.1.0 LANGUAGES C CXX)
set(PROJECT_TARGET_NAME ${PROJECT_NAME})

include_directories(
    ${PROJECT_TARGET_NAME} 
    include)

set(SRC_FILES 
    src/bd/bd.cpp)

add_library(${PROJECT_TARGET_NAME} SHARED
    ${SRC_FILES})

