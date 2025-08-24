conan install . --output-folder=build --build=missing -s build_type=Debug
cmake --preset conan-debug
cmake --build --preset conan-debug