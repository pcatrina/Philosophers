# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pcatrina/Desktop/workspace/Philosophers/philo_two

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pcatrina/Desktop/workspace/Philosophers/philo_two/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philo_two.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_two.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_two.dir/flags.make

CMakeFiles/philo_two.dir/main.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pcatrina/Desktop/workspace/Philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_two.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/main.c.o   -c /Users/pcatrina/Desktop/workspace/Philosophers/philo_two/main.c

CMakeFiles/philo_two.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/pcatrina/Desktop/workspace/Philosophers/philo_two/main.c > CMakeFiles/philo_two.dir/main.c.i

CMakeFiles/philo_two.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/pcatrina/Desktop/workspace/Philosophers/philo_two/main.c -o CMakeFiles/philo_two.dir/main.c.s

# Object files for target philo_two
philo_two_OBJECTS = \
"CMakeFiles/philo_two.dir/main.c.o"

# External object files for target philo_two
philo_two_EXTERNAL_OBJECTS =

philo_two: CMakeFiles/philo_two.dir/main.c.o
philo_two: CMakeFiles/philo_two.dir/build.make
philo_two: CMakeFiles/philo_two.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pcatrina/Desktop/workspace/Philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable philo_two"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_two.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_two.dir/build: philo_two

.PHONY : CMakeFiles/philo_two.dir/build

CMakeFiles/philo_two.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_two.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_two.dir/clean

CMakeFiles/philo_two.dir/depend:
	cd /Users/pcatrina/Desktop/workspace/Philosophers/philo_two/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pcatrina/Desktop/workspace/Philosophers/philo_two /Users/pcatrina/Desktop/workspace/Philosophers/philo_two /Users/pcatrina/Desktop/workspace/Philosophers/philo_two/cmake-build-debug /Users/pcatrina/Desktop/workspace/Philosophers/philo_two/cmake-build-debug /Users/pcatrina/Desktop/workspace/Philosophers/philo_two/cmake-build-debug/CMakeFiles/philo_two.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_two.dir/depend

