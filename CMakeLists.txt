project(manchester-cpp)
ADD_DEFINITIONS(
    -std=c++11
)
cmake_minimum_required(VERSION 2.8)
include_directories(".", "manchester")
aux_source_directory(. SRC_LIST)
aux_source_directory(manchester MANCHESTER_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST} ${MANCHESTER_LIST})

