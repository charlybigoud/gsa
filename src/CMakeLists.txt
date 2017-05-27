cmake_minimum_required(VERSION 2.8)

add_library(gsa
    simulated_annealing.cpp
    display.cpp
    colors.cpp
    utils.cpp
)

target_include_directories(gsa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
