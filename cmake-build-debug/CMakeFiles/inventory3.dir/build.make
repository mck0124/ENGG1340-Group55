# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/M1/Documents/GitHub/Initial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/M1/Documents/GitHub/Initial/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/inventory3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/inventory3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/inventory3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inventory3.dir/flags.make

CMakeFiles/inventory3.dir/UI/inventory3.cpp.o: CMakeFiles/inventory3.dir/flags.make
CMakeFiles/inventory3.dir/UI/inventory3.cpp.o: /Users/M1/Documents/GitHub/Initial/UI/inventory3.cpp
CMakeFiles/inventory3.dir/UI/inventory3.cpp.o: CMakeFiles/inventory3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/M1/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inventory3.dir/UI/inventory3.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inventory3.dir/UI/inventory3.cpp.o -MF CMakeFiles/inventory3.dir/UI/inventory3.cpp.o.d -o CMakeFiles/inventory3.dir/UI/inventory3.cpp.o -c /Users/M1/Documents/GitHub/Initial/UI/inventory3.cpp

CMakeFiles/inventory3.dir/UI/inventory3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inventory3.dir/UI/inventory3.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/M1/Documents/GitHub/Initial/UI/inventory3.cpp > CMakeFiles/inventory3.dir/UI/inventory3.cpp.i

CMakeFiles/inventory3.dir/UI/inventory3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inventory3.dir/UI/inventory3.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/M1/Documents/GitHub/Initial/UI/inventory3.cpp -o CMakeFiles/inventory3.dir/UI/inventory3.cpp.s

# Object files for target inventory3
inventory3_OBJECTS = \
"CMakeFiles/inventory3.dir/UI/inventory3.cpp.o"

# External object files for target inventory3
inventory3_EXTERNAL_OBJECTS =

inventory3: CMakeFiles/inventory3.dir/UI/inventory3.cpp.o
inventory3: CMakeFiles/inventory3.dir/build.make
inventory3: CMakeFiles/inventory3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/M1/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable inventory3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inventory3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inventory3.dir/build: inventory3
.PHONY : CMakeFiles/inventory3.dir/build

CMakeFiles/inventory3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inventory3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inventory3.dir/clean

CMakeFiles/inventory3.dir/depend:
	cd /Users/M1/Documents/GitHub/Initial/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/M1/Documents/GitHub/Initial /Users/M1/Documents/GitHub/Initial /Users/M1/Documents/GitHub/Initial/cmake-build-debug /Users/M1/Documents/GitHub/Initial/cmake-build-debug /Users/M1/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles/inventory3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inventory3.dir/depend

