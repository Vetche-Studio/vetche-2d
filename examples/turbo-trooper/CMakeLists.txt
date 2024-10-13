cmake_minimum_required(VERSION 3.5.0)
project(Turbo-Trooper VERSION 0.1.0 LANGUAGES C CXX)
set(PROJECT_TARGET_NAME ${PROJECT_NAME})

include_directories(
    ${PROJECT_TARGET_NAME}
    ../../include
    .)

set(SRC_FILES 
    main.cpp)

add_executable(${PROJECT_TARGET_NAME} main.cpp)

add_subdirectory(../../ ./bin)

target_link_libraries(${PROJECT_TARGET_NAME} BrainDust-Toolbox)