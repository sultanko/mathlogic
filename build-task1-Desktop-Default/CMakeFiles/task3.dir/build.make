# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sultan/Documents/Year2/mat_logic/task3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/task3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task3.dir/flags.make

CMakeFiles/task3.dir/main.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/main.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/main.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/main.cpp

CMakeFiles/task3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/main.cpp > CMakeFiles/task3.dir/main.cpp.i

CMakeFiles/task3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/main.cpp -o CMakeFiles/task3.dir/main.cpp.s

CMakeFiles/task3.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/main.cpp.o.requires

CMakeFiles/task3.dir/main.cpp.o.provides: CMakeFiles/task3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/main.cpp.o.provides

CMakeFiles/task3.dir/main.cpp.o.provides.build: CMakeFiles/task3.dir/main.cpp.o

CMakeFiles/task3.dir/Parser/Expression.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/Expression.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/Expression.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/Expression.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/Expression.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/Expression.cpp

CMakeFiles/task3.dir/Parser/Expression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/Expression.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/Expression.cpp > CMakeFiles/task3.dir/Parser/Expression.cpp.i

CMakeFiles/task3.dir/Parser/Expression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/Expression.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/Expression.cpp -o CMakeFiles/task3.dir/Parser/Expression.cpp.s

CMakeFiles/task3.dir/Parser/Expression.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/Expression.cpp.o.requires

CMakeFiles/task3.dir/Parser/Expression.cpp.o.provides: CMakeFiles/task3.dir/Parser/Expression.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/Expression.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/Expression.cpp.o.provides

CMakeFiles/task3.dir/Parser/Expression.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/Expression.cpp.o

CMakeFiles/task3.dir/Parser/Parser.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/Parser.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/Parser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/Parser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/Parser.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/Parser.cpp

CMakeFiles/task3.dir/Parser/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/Parser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/Parser.cpp > CMakeFiles/task3.dir/Parser/Parser.cpp.i

CMakeFiles/task3.dir/Parser/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/Parser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/Parser.cpp -o CMakeFiles/task3.dir/Parser/Parser.cpp.s

CMakeFiles/task3.dir/Parser/Parser.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/Parser.cpp.o.requires

CMakeFiles/task3.dir/Parser/Parser.cpp.o.provides: CMakeFiles/task3.dir/Parser/Parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/Parser.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/Parser.cpp.o.provides

CMakeFiles/task3.dir/Parser/Parser.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/Parser.cpp.o

CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/BinaryExpression.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/BinaryExpression.cpp

CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/BinaryExpression.cpp > CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.i

CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/BinaryExpression.cpp -o CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.s

CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o.requires

CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o.provides: CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o.provides

CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o

CMakeFiles/task3.dir/Parser/conjunction.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/conjunction.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/conjunction.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/conjunction.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/conjunction.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/conjunction.cpp

CMakeFiles/task3.dir/Parser/conjunction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/conjunction.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/conjunction.cpp > CMakeFiles/task3.dir/Parser/conjunction.cpp.i

CMakeFiles/task3.dir/Parser/conjunction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/conjunction.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/conjunction.cpp -o CMakeFiles/task3.dir/Parser/conjunction.cpp.s

CMakeFiles/task3.dir/Parser/conjunction.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/conjunction.cpp.o.requires

CMakeFiles/task3.dir/Parser/conjunction.cpp.o.provides: CMakeFiles/task3.dir/Parser/conjunction.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/conjunction.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/conjunction.cpp.o.provides

CMakeFiles/task3.dir/Parser/conjunction.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/conjunction.cpp.o

CMakeFiles/task3.dir/Parser/disjunction.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/disjunction.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/disjunction.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/disjunction.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/disjunction.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/disjunction.cpp

CMakeFiles/task3.dir/Parser/disjunction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/disjunction.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/disjunction.cpp > CMakeFiles/task3.dir/Parser/disjunction.cpp.i

CMakeFiles/task3.dir/Parser/disjunction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/disjunction.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/disjunction.cpp -o CMakeFiles/task3.dir/Parser/disjunction.cpp.s

CMakeFiles/task3.dir/Parser/disjunction.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/disjunction.cpp.o.requires

CMakeFiles/task3.dir/Parser/disjunction.cpp.o.provides: CMakeFiles/task3.dir/Parser/disjunction.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/disjunction.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/disjunction.cpp.o.provides

CMakeFiles/task3.dir/Parser/disjunction.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/disjunction.cpp.o

CMakeFiles/task3.dir/Parser/implication.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/implication.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/implication.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/implication.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/implication.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/implication.cpp

CMakeFiles/task3.dir/Parser/implication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/implication.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/implication.cpp > CMakeFiles/task3.dir/Parser/implication.cpp.i

CMakeFiles/task3.dir/Parser/implication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/implication.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/implication.cpp -o CMakeFiles/task3.dir/Parser/implication.cpp.s

CMakeFiles/task3.dir/Parser/implication.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/implication.cpp.o.requires

CMakeFiles/task3.dir/Parser/implication.cpp.o.provides: CMakeFiles/task3.dir/Parser/implication.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/implication.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/implication.cpp.o.provides

CMakeFiles/task3.dir/Parser/implication.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/implication.cpp.o

CMakeFiles/task3.dir/Parser/negation.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/negation.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/negation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/negation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/negation.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/negation.cpp

CMakeFiles/task3.dir/Parser/negation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/negation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/negation.cpp > CMakeFiles/task3.dir/Parser/negation.cpp.i

CMakeFiles/task3.dir/Parser/negation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/negation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/negation.cpp -o CMakeFiles/task3.dir/Parser/negation.cpp.s

CMakeFiles/task3.dir/Parser/negation.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/negation.cpp.o.requires

CMakeFiles/task3.dir/Parser/negation.cpp.o.provides: CMakeFiles/task3.dir/Parser/negation.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/negation.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/negation.cpp.o.provides

CMakeFiles/task3.dir/Parser/negation.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/negation.cpp.o

CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/unaryexpression.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/unaryexpression.cpp

CMakeFiles/task3.dir/Parser/unaryexpression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/unaryexpression.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/unaryexpression.cpp > CMakeFiles/task3.dir/Parser/unaryexpression.cpp.i

CMakeFiles/task3.dir/Parser/unaryexpression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/unaryexpression.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/unaryexpression.cpp -o CMakeFiles/task3.dir/Parser/unaryexpression.cpp.s

CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o.requires

CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o.provides: CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o.provides

CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o

CMakeFiles/task3.dir/Parser/variable.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/variable.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/variable.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/variable.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/variable.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/variable.cpp

CMakeFiles/task3.dir/Parser/variable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/variable.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/variable.cpp > CMakeFiles/task3.dir/Parser/variable.cpp.i

CMakeFiles/task3.dir/Parser/variable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/variable.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/variable.cpp -o CMakeFiles/task3.dir/Parser/variable.cpp.s

CMakeFiles/task3.dir/Parser/variable.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/variable.cpp.o.requires

CMakeFiles/task3.dir/Parser/variable.cpp.o.provides: CMakeFiles/task3.dir/Parser/variable.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/variable.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/variable.cpp.o.provides

CMakeFiles/task3.dir/Parser/variable.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/variable.cpp.o

CMakeFiles/task3.dir/Parser/Proofment.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/Parser/Proofment.cpp.o: /home/sultan/Documents/Year2/mat_logic/task3/Parser/Proofment.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/task3.dir/Parser/Proofment.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/Parser/Proofment.cpp.o -c /home/sultan/Documents/Year2/mat_logic/task3/Parser/Proofment.cpp

CMakeFiles/task3.dir/Parser/Proofment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/Parser/Proofment.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sultan/Documents/Year2/mat_logic/task3/Parser/Proofment.cpp > CMakeFiles/task3.dir/Parser/Proofment.cpp.i

CMakeFiles/task3.dir/Parser/Proofment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/Parser/Proofment.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sultan/Documents/Year2/mat_logic/task3/Parser/Proofment.cpp -o CMakeFiles/task3.dir/Parser/Proofment.cpp.s

CMakeFiles/task3.dir/Parser/Proofment.cpp.o.requires:
.PHONY : CMakeFiles/task3.dir/Parser/Proofment.cpp.o.requires

CMakeFiles/task3.dir/Parser/Proofment.cpp.o.provides: CMakeFiles/task3.dir/Parser/Proofment.cpp.o.requires
	$(MAKE) -f CMakeFiles/task3.dir/build.make CMakeFiles/task3.dir/Parser/Proofment.cpp.o.provides.build
.PHONY : CMakeFiles/task3.dir/Parser/Proofment.cpp.o.provides

CMakeFiles/task3.dir/Parser/Proofment.cpp.o.provides.build: CMakeFiles/task3.dir/Parser/Proofment.cpp.o

# Object files for target task3
task3_OBJECTS = \
"CMakeFiles/task3.dir/main.cpp.o" \
"CMakeFiles/task3.dir/Parser/Expression.cpp.o" \
"CMakeFiles/task3.dir/Parser/Parser.cpp.o" \
"CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o" \
"CMakeFiles/task3.dir/Parser/conjunction.cpp.o" \
"CMakeFiles/task3.dir/Parser/disjunction.cpp.o" \
"CMakeFiles/task3.dir/Parser/implication.cpp.o" \
"CMakeFiles/task3.dir/Parser/negation.cpp.o" \
"CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o" \
"CMakeFiles/task3.dir/Parser/variable.cpp.o" \
"CMakeFiles/task3.dir/Parser/Proofment.cpp.o"

# External object files for target task3
task3_EXTERNAL_OBJECTS =

/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/main.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/Expression.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/Parser.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/conjunction.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/disjunction.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/implication.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/negation.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/variable.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/Parser/Proofment.cpp.o
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/build.make
/home/sultan/Documents/Year2/mat_logic/task3/build/task3: CMakeFiles/task3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/sultan/Documents/Year2/mat_logic/task3/build/task3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task3.dir/build: /home/sultan/Documents/Year2/mat_logic/task3/build/task3
.PHONY : CMakeFiles/task3.dir/build

CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/main.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/Expression.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/Parser.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/BinaryExpression.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/conjunction.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/disjunction.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/implication.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/negation.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/unaryexpression.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/variable.cpp.o.requires
CMakeFiles/task3.dir/requires: CMakeFiles/task3.dir/Parser/Proofment.cpp.o.requires
.PHONY : CMakeFiles/task3.dir/requires

CMakeFiles/task3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task3.dir/clean

CMakeFiles/task3.dir/depend:
	cd /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sultan/Documents/Year2/mat_logic/task3 /home/sultan/Documents/Year2/mat_logic/task3 /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default /home/sultan/Documents/Year2/mat_logic/build-task1-Desktop-Default/CMakeFiles/task3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task3.dir/depend

