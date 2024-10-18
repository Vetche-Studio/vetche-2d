cmake_minimum_required(VERSION 3.5.0)
project(Turbo-Trooper VERSION 0.1.0 LANGUAGES C CXX)

include_directories(
    ${PROJECT_NAME}
    ../../src
    .)

set(BRAINDUST_PLATFORM "NDS")

add_subdirectory(../../ ./bin)

add_brain_dust_game(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)



# add_executable(${PROJECT_NAME} main.cpp)
# target_link_libraries(${PROJECT_NAME} PUBLIC nds9)
# target_compile_options(${PROJECT_NAME} PRIVATE
#     -g -O0 -Wall -fno-rtti -fno-exceptions
#     -march=armv5te 
#     -mtune=arm946e-s 
#     -fomit-frame-pointer
#     -ffast-math)
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.nds
#     COMMENT "Converting ELF to NDS")