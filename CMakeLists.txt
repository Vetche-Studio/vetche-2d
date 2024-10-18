cmake_minimum_required(VERSION 3.5.0)
project(BrainDust-Toolbox VERSION 0.1.0 LANGUAGES C CXX)
set(ENGINE_TARGET_NAME ${PROJECT_NAME})

include(Playdate.cmake)

include_directories(
    ${ENGINE_TARGET_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib/src
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/playdate-cpp/inc)

set(SRC_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vetche/vetche.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vetche/core/core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vetche/layer/layerstack.cpp
)

if(BRAINDUST_PLATFORM)

    if(${BRAINDUST_PLATFORM} STREQUAL "PLAYDATE")

        set(CMAKE_CXX_STANDARD 20)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
        set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
        set(CMAKE_XCODE_GENERATE_SCHEME TRUE)

        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/playdate-cpp)
        add_library(${ENGINE_TARGET_NAME} STATIC ${SRC_FILES})
    elseif(${BRAINDUST_PLATFORM} STREQUAL "LINUX_X11")
        include_directories(
            ${ENGINE_TARGET_NAME} 
            ./vendor/raylib/src)
        set(LINUX_X11_SRC_FILES 
            src/vetche/platform/raylib/rendering/renderer.cpp
            src/vetche/platform/raylib/system/runner.cpp
        )
        
        set(SRC_FILES ${SRC_FILES} ${LINUX_X11_SRC_FILES})
        
        add_compile_definitions(BUILD_LINUX_X11)
            
        set(RAYLIB_VERSION 5.0)
        add_subdirectory(vendor/raylib)
        add_library(${ENGINE_TARGET_NAME} STATIC ${SRC_FILES})
        target_link_libraries(${ENGINE_TARGET_NAME} raylib)
    elseif(${BRAINDUST_PLATFORM} STREQUAL "NDS")
        add_compile_definitions(BUILD_NDS)
        add_library(${ENGINE_TARGET_NAME} STATIC ${SRC_FILES})
        include_directories(${ENGINE_TARGET_NAME} $ENV{DEVKITPRO}/libnds/include)
        # install(${ENGINE_TARGET_NAME})
    else()
        message("BRAINDUST: Error on setup: platform not supported: " ${BRAINDUST_PLATFORM})
    endif()
else()
    message("BRAINDUST: Error on setup: no platform defined")
endif()

function(add_brain_dust_game GAME_NAME GAME_SRC_FILES)
    message("Added game: " ${GAME_NAME})
    if(${BRAINDUST_PLATFORM} STREQUAL "LINUX_X11")
        add_executable(${GAME_NAME} ${GAME_SRC_FILES})
        target_link_libraries(${GAME_NAME} PUBLIC BrainDust-Toolbox)
    elseif(${BRAINDUST_PLATFORM} STREQUAL "PLAYDATE")
        add_playdate_application_modified(${GAME_NAME})
        target_link_libraries(${GAME_NAME} PUBLIC BrainDust-Toolbox pdcpp_core)
        target_sources(${GAME_NAME} PUBLIC ${GAME_SRC_FILES})
    elseif(${BRAINDUST_PLATFORM} STREQUAL "NDS")
        add_executable(${GAME_NAME} ${GAME_SRC_FILES})
        target_link_libraries(${GAME_NAME} PUBLIC BrainDust-Toolbox)
        nds_create_rom(${GAME_NAME})
        target_compile_options(${GAME_NAME} PRIVATE
            -g -O2 -Wall)
        add_custom_command(TARGET ${GAME_NAME} POST_BUILD
            COMMAND ${CMAKE_OBJCOPY} -O binary ${GAME_NAME}.elf ${GAME_NAME}.nds
            COMMENT "Converting ELF to NDS")
        # target_link_libraries(${GAME_NAME} nds)
    else()
        message("BRAINDUST: Error on add game: platform not supported " ${BRAINDUST_PLATFORM})
    endif()

endfunction()
