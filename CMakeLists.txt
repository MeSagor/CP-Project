cmake_minimum_required(VERSION 2.8.4)
project(CP-Project)

add_executable(output output/main.cpp)
add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp" )

ADD_DEFINITIONS(-std=c++17)

add_executable(test ${TASKS} ${HEADERS})
