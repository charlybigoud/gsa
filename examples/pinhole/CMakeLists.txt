cmake_minimum_required(VERSION 2.8)

project(pinhole)

add_executable(pinhole src/pinhole.cpp)

target_link_libraries(pinhole gsa)
