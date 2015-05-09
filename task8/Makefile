#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
CC=g++
C_FLAGS=-c -std=c++11 -Wall
LD_FLAGS=-lgmp
SOURCEC=main.cpp Parser/Expression.cpp Parser/Parser.cpp Parser/CNF.cpp 
OBJECTS=$(SOURCEC:.cpp=.o)
EXECUTABLE=task8

all: $(SOURCEC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LD_FLAGS) 

.cpp.o:
	$(CC) $(C_FLAGS) $< -o $@

