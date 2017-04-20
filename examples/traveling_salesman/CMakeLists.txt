cmake_minimum_required(VERSION 2.8)

project(traveling_salesman)

add_executable(traveling_salesman src/traveling_salesman.cpp)

target_link_libraries(traveling_salesman simulated_annealing display)
