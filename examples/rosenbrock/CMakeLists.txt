cmake_minimum_required(VERSION 2.8)

project(rosenbrock)

add_executable(rosenbrock src/rosenbrock.cpp)

target_link_libraries(rosenbrock simulated_annealing display)
