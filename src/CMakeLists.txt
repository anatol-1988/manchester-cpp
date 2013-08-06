cmake_minimum_required(VERSION 2.8)
include_directories("../include")
add_library(man-decoder-lib decoder.cpp)
add_library(man-encoder-lib encoder.cpp)
