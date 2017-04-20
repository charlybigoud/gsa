cmake_minimum_required (VERSION 2.8)

add_library (simulated_annealing simulated_annealing.cpp)
add_library (display display.cpp)

target_include_directories (simulated_annealing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories (display PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
