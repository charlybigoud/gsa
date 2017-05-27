cmake_minimum_required(VERSION 2.8)

project(simple_function)

add_executable(simple_function src/simple_function.cpp)

target_link_libraries(simple_function gsa)
