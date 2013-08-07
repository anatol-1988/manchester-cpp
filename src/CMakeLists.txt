cmake_minimum_required(VERSION 2.8)
include_directories("../include")
add_library(dif-decoder-lib dif-decoder.cpp)
add_library(dif-encoder-lib dif-encoder.cpp)
