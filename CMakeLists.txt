cmake_minimum_required(VERSION 3.16)
project(JI-To-Do-List)

set(CMAKE_CXX_STANDARD 11)

add_executable(JI-To-Do-List main.cpp task.cpp cli.cpp suggested_list_generator.cpp fileInput.cpp fileOutput.cpp)
add_executable(suggested_list suggested_list_generator.cpp task.cpp)
add_executable(fileInput fileInput.cpp)
add_executable(fileOutput fileOutput.cpp)
