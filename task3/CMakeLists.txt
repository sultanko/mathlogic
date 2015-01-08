cmake_minimum_required(VERSION 2.8.4)
project(task3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})

set(SOURCE_FILES main.cpp Parser/Expression.cpp Parser/ParserUtils.cpp Parser/BinaryExpression.cpp
Parser/conjunction.cpp Parser/disjunction.cpp Parser/implication.cpp Parser/negation.cpp Parser/unaryexpression.cpp Parser/variable.cpp
Parser/ExpressionUtils.cpp)
add_executable(task3 ${SOURCE_FILES})