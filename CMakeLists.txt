cmake_minimum_required(VERSION 3.29)
project(compact_simple_graph)

set(CMAKE_CXX_STANDARD 20)

add_library(compact_simple_graph STATIC
        csg/core.h
        csg/core.cpp)

target_include_directories(compact_simple_graph PUBLIC "${CMAKE_CURRENT_LIST_DIR}")