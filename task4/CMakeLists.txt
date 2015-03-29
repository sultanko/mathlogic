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
Parser/kvantor.cpp Parser/kvantorall.cpp Parser/kvantorexist.cpp
Parser/predicat.cpp Parser/functionmy.cpp
Parser/multiplication.cpp Parser/subtraction.cpp Parser/addition.cpp Parser/equality.cpp

Proof/proofcheck.cpp Proof/proofdeduction.cpp Proof/proofgenerate.cpp
)
add_executable(task4 ${SOURCE_FILES} Parser/Zero.cpp Parser/Zero.h Parser/Shtrix.cpp Parser/Shtrix.h Parser/FArguments.cpp Parser/FArguments.h)
