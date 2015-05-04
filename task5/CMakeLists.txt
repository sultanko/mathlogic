cmake_minimum_required(VERSION 2.8.4)
project(task4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})

set( SOURCE_FILES
main.cpp

Parser/Expression.cpp Parser/Parser.cpp Parser/BinaryExpression.cpp
Parser/conjunction.cpp Parser/disjunction.cpp Parser/implication.cpp Parser/negation.cpp
Parser/unaryexpression.cpp Parser/variable.cpp

Kripke/PairKripke.cpp
Kripke/World.cpp Kripke/Tree.cpp Kripke/Generator.cpp
)
add_executable(task5 ${SOURCE_FILES} Kripke/TreeView.cpp Kripke/TreeView.h)
