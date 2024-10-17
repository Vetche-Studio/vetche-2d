cmake_minimum_required(VERSION 3.5.0)
project(BrainDust-Toolbox VERSION 0.1.0 LANGUAGES C CXX)
set(PROJECT_TARGET_NAME ${PROJECT_NAME})

include_directories(
    ${PROJECT_TARGET_NAME} 
    ./src
    ./vendor/raylib/src)
    
set(RAYLIB_VERSION 5.0)

set(SRC_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bd/bd.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bd/core/core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bd/layer/layerstack.cpp
)

set(LINUX_X11_SRC_FILES 
    src/bd/platform/linux/rendering/renderer.cpp
)


if(BRAINDUST_PLATFORM)
    if(${BRAINDUST_PLATFORM} STREQUAL "PLAYDATE")

        set(CMAKE_CXX_STANDARD 20)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
        set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
        set(CMAKE_XCODE_GENERATE_SCHEME TRUE)

        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/playdate-cpp)
    endif()
else()

endif()


function(add_brain_dust_toolbox_executable GAME_NAME GAME_SRC_FILES)

    if(${BRAINDUST_PLATFORM} STREQUAL "PLAYDATE")

        add_playdate_application(${GAME_NAME})
        target_sources(${PROJECT_TARGET_NAME} PUBLIC ${SRC_FILES} ${GAME_SRC_FILES})
        
    endif()

endfunction()



