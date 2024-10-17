cmake_minimum_required(VERSION 3.5.0)
project(BrainDust-Toolbox VERSION 0.1.0 LANGUAGES C CXX)
set(PROJECT_TARGET_NAME ${PROJECT_NAME})

include_directories(
    ${PROJECT_TARGET_NAME} 
    ./src
    ./vendor/raylib/src)
    
set(RAYLIB_VERSION 5.0)
set(SRC_FILES 
    src/bd/bd.cpp
    src/bd/core/core.cpp
    src/bd/layer/layerstack.cpp
)

set(LINUX_X11_SRC_FILES 
    src/bd/platform/linux/rendering/renderer.cpp
)

add_subdirectory(vendor/raylib)

# TODO: Make this library dynamic and fix the problem where raylib doesn't work with SHARED
add_library(${PROJECT_TARGET_NAME} STATIC
    ${SRC_FILES}
    ${LINUX_X11_SRC_FILES})

target_link_libraries(${PROJECT_TARGET_NAME} raylib)