#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
CC=g++
C_FLAGS=-c -std=c++11 -Wall
LD_FLAGS=
SOURCEC=main.cpp \
Parser/Expression.cpp Parser/Parser.cpp Parser/BinaryExpression.cpp \
Parser/conjunction.cpp Parser/disjunction.cpp Parser/implication.cpp Parser/negation.cpp \
Parser/unaryexpression.cpp Parser/variable.cpp \
Kripke/PairKripke.cpp \
Kripke/World.cpp Kripke/Tree.cpp Kripke/Generator.cpp Kripke/TreeView.cpp
OBJECTS=$(SOURCEC:.cpp=.o)
EXECUTABLE=task5

all: $(SOURCEC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LD_FLAGS) 

.cpp.o:
	$(CC) $(C_FLAGS) $< -o $@

