cmake_minimum_required(VERSION 2.8.4)
project(task1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})

set(SOURCE_FILES main.cpp Expression.cpp ParserUtils.cpp BinaryExpression.cpp
conjunction.cpp disjunction.cpp implication.cpp negation.cpp unaryexpression.cpp variable.cpp
ExpressionUtils.cpp)
add_executable(task1 ${SOURCE_FILES})