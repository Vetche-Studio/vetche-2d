#!/usr/bin/bash
BUILD_DIR=./_nds_build
$DEVKITPRO/portlibs/nds/bin/arm-none-eabi-cmake -B $BUILD_DIR -S .
cd $BUILD_DIR
make
cd ..