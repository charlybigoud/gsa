cmake_minimum_required(VERSION 2.8)

project(gsa)

add_definitions(-std=c++1y -O3)

add_subdirectory(src)

add_subdirectory(examples/pinhole)
add_subdirectory(examples/rosenbrock)
add_subdirectory(examples/simple_function)
add_subdirectory(examples/simple_function2)
add_subdirectory(examples/traveling_salesman)
