cmake_minimum_required(VERSION 3.16)
project(JI-To-Do-List)

set(CMAKE_CXX_STANDARD 11)

add_executable(JI-To-Do-List main.cpp task.cpp cli.cpp suggestedList.cpp fileInput.cpp fileOutput.cpp)
add_executable(suggestedList suggestedList.cpp task.cpp)

add_executable(fileInput fileInput.cpp)
add_executable(fileOutput fileOutput.cpp)
