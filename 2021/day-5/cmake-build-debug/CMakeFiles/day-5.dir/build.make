# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sua/Documents/advent-code/2021/day-5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sua/Documents/advent-code/2021/day-5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/day-5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/day-5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/day-5.dir/flags.make

CMakeFiles/day-5.dir/main.cpp.o: CMakeFiles/day-5.dir/flags.make
CMakeFiles/day-5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sua/Documents/advent-code/2021/day-5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/day-5.dir/main.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/day-5.dir/main.cpp.o -c /home/sua/Documents/advent-code/2021/day-5/main.cpp

CMakeFiles/day-5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day-5.dir/main.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sua/Documents/advent-code/2021/day-5/main.cpp > CMakeFiles/day-5.dir/main.cpp.i

CMakeFiles/day-5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day-5.dir/main.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sua/Documents/advent-code/2021/day-5/main.cpp -o CMakeFiles/day-5.dir/main.cpp.s

CMakeFiles/day-5.dir/Point.cpp.o: CMakeFiles/day-5.dir/flags.make
CMakeFiles/day-5.dir/Point.cpp.o: ../Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sua/Documents/advent-code/2021/day-5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/day-5.dir/Point.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/day-5.dir/Point.cpp.o -c /home/sua/Documents/advent-code/2021/day-5/Point.cpp

CMakeFiles/day-5.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day-5.dir/Point.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sua/Documents/advent-code/2021/day-5/Point.cpp > CMakeFiles/day-5.dir/Point.cpp.i

CMakeFiles/day-5.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day-5.dir/Point.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sua/Documents/advent-code/2021/day-5/Point.cpp -o CMakeFiles/day-5.dir/Point.cpp.s

# Object files for target day-5
day__5_OBJECTS = \
"CMakeFiles/day-5.dir/main.cpp.o" \
"CMakeFiles/day-5.dir/Point.cpp.o"

# External object files for target day-5
day__5_EXTERNAL_OBJECTS =

day-5: CMakeFiles/day-5.dir/main.cpp.o
day-5: CMakeFiles/day-5.dir/Point.cpp.o
day-5: CMakeFiles/day-5.dir/build.make
day-5: CMakeFiles/day-5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sua/Documents/advent-code/2021/day-5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable day-5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/day-5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/day-5.dir/build: day-5

.PHONY : CMakeFiles/day-5.dir/build

CMakeFiles/day-5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/day-5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/day-5.dir/clean

CMakeFiles/day-5.dir/depend:
	cd /home/sua/Documents/advent-code/2021/day-5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sua/Documents/advent-code/2021/day-5 /home/sua/Documents/advent-code/2021/day-5 /home/sua/Documents/advent-code/2021/day-5/cmake-build-debug /home/sua/Documents/advent-code/2021/day-5/cmake-build-debug /home/sua/Documents/advent-code/2021/day-5/cmake-build-debug/CMakeFiles/day-5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/day-5.dir/depend
