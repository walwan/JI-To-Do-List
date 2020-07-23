cmake_minimum_required(VERSION 3.16)
project(JI-To-Do-List)

set(CMAKE_CXX_STANDARD 11)

add_executable(JI-To-Do-List main.cpp task.cpp)
add_executable(suggested_list suggested_list_generator.cpp)
