# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/vito/clion/clion-2019.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vito/clion/clion-2019.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/vito/CLionProjects/word Ladder"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/vito/CLionProjects/word Ladder/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/word_Ladder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/word_Ladder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/word_Ladder.dir/flags.make

CMakeFiles/word_Ladder.dir/main.cpp.o: CMakeFiles/word_Ladder.dir/flags.make
CMakeFiles/word_Ladder.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/vito/CLionProjects/word Ladder/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/word_Ladder.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/word_Ladder.dir/main.cpp.o -c "/home/vito/CLionProjects/word Ladder/main.cpp"

CMakeFiles/word_Ladder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/word_Ladder.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/vito/CLionProjects/word Ladder/main.cpp" > CMakeFiles/word_Ladder.dir/main.cpp.i

CMakeFiles/word_Ladder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/word_Ladder.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/vito/CLionProjects/word Ladder/main.cpp" -o CMakeFiles/word_Ladder.dir/main.cpp.s

# Object files for target word_Ladder
word_Ladder_OBJECTS = \
"CMakeFiles/word_Ladder.dir/main.cpp.o"

# External object files for target word_Ladder
word_Ladder_EXTERNAL_OBJECTS =

word_Ladder: CMakeFiles/word_Ladder.dir/main.cpp.o
word_Ladder: CMakeFiles/word_Ladder.dir/build.make
word_Ladder: CMakeFiles/word_Ladder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/vito/CLionProjects/word Ladder/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable word_Ladder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/word_Ladder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/word_Ladder.dir/build: word_Ladder

.PHONY : CMakeFiles/word_Ladder.dir/build

CMakeFiles/word_Ladder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/word_Ladder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/word_Ladder.dir/clean

CMakeFiles/word_Ladder.dir/depend:
	cd "/home/vito/CLionProjects/word Ladder/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/vito/CLionProjects/word Ladder" "/home/vito/CLionProjects/word Ladder" "/home/vito/CLionProjects/word Ladder/cmake-build-debug" "/home/vito/CLionProjects/word Ladder/cmake-build-debug" "/home/vito/CLionProjects/word Ladder/cmake-build-debug/CMakeFiles/word_Ladder.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/word_Ladder.dir/depend

