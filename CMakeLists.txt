project(manchester-cpp)
ADD_DEFINITIONS(
    -std=c++11
)
cmake_minimum_required(VERSION 2.8)
enable_testing()
include_directories("include")
add_subdirectory(src)
add_subdirectory(tests)


