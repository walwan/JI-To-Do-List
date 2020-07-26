cmake_minimum_required(VERSION 3.16)
project(JI-To-Do-List)

set(CMAKE_CXX_STANDARD 11)

add_executable(JI-To-Do-List main.cpp task.cpp cli.cpp cli.h)
add_executable(suggested_list suggested_list_generator.cpp)
add_executable(fileInput fileInput.cpp)