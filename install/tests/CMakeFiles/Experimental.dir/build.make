# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia/install

# Utility rule file for Experimental.

# Include the progress variables for this target.
include tests/CMakeFiles/Experimental.dir/progress.make

tests/CMakeFiles/Experimental:
	cd /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia/install/tests && /usr/bin/ctest -D Experimental

Experimental: tests/CMakeFiles/Experimental
Experimental: tests/CMakeFiles/Experimental.dir/build.make

.PHONY : Experimental

# Rule to build all files generated by this target.
tests/CMakeFiles/Experimental.dir/build: Experimental

.PHONY : tests/CMakeFiles/Experimental.dir/build

tests/CMakeFiles/Experimental.dir/clean:
	cd /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia/install/tests && $(CMAKE_COMMAND) -P CMakeFiles/Experimental.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/Experimental.dir/clean

tests/CMakeFiles/Experimental.dir/depend:
	cd /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia/install && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia/tests /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia/install /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia/install/tests /home/archman/CodeProj/cpp_projects/cytopia-myfork/Cytopia/install/tests/CMakeFiles/Experimental.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/Experimental.dir/depend

