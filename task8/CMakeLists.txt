cmake_minimum_required(VERSION 3.1)
project(task8)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -pedantic")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(SOURCE_FILES main.cpp)
add_executable(task8 ${SOURCE_FILES} Parser/Expression.cpp Parser/Expression.h Parser/Parser.cpp Parser/Parser.h Parser/CNF.cpp Parser/CNF.h)