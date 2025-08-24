conan install . --output-folder=build --build=missing -s build_type=Debug
cmake --preset conan-default
cmake --build --preset conan-debug