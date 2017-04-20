cmake_minimum_required(VERSION 2.8)

project(simple_function2)

add_executable(simple_function2 src/simple_function2.cpp)

target_link_libraries(simple_function2 simulated_annealing display)
