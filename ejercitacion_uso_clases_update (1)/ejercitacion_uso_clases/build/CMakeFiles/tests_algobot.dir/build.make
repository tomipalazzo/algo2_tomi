# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/build"

# Include any dependencies generated for this target.
include CMakeFiles/tests_algobot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tests_algobot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests_algobot.dir/flags.make

CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.o: CMakeFiles/tests_algobot.dir/flags.make
CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.o: ../tests/tests_algobot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.o -c "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/tests/tests_algobot.cpp"

CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/tests/tests_algobot.cpp" > CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.i

CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/tests/tests_algobot.cpp" -o CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.s

CMakeFiles/tests_algobot.dir/src/algobot.cpp.o: CMakeFiles/tests_algobot.dir/flags.make
CMakeFiles/tests_algobot.dir/src/algobot.cpp.o: ../src/algobot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests_algobot.dir/src/algobot.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests_algobot.dir/src/algobot.cpp.o -c "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/src/algobot.cpp"

CMakeFiles/tests_algobot.dir/src/algobot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests_algobot.dir/src/algobot.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/src/algobot.cpp" > CMakeFiles/tests_algobot.dir/src/algobot.cpp.i

CMakeFiles/tests_algobot.dir/src/algobot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests_algobot.dir/src/algobot.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/src/algobot.cpp" -o CMakeFiles/tests_algobot.dir/src/algobot.cpp.s

# Object files for target tests_algobot
tests_algobot_OBJECTS = \
"CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.o" \
"CMakeFiles/tests_algobot.dir/src/algobot.cpp.o"

# External object files for target tests_algobot
tests_algobot_EXTERNAL_OBJECTS =

tests_algobot: CMakeFiles/tests_algobot.dir/tests/tests_algobot.cpp.o
tests_algobot: CMakeFiles/tests_algobot.dir/src/algobot.cpp.o
tests_algobot: CMakeFiles/tests_algobot.dir/build.make
tests_algobot: libgtest.a
tests_algobot: libgtest_main.a
tests_algobot: CMakeFiles/tests_algobot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tests_algobot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests_algobot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests_algobot.dir/build: tests_algobot

.PHONY : CMakeFiles/tests_algobot.dir/build

CMakeFiles/tests_algobot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests_algobot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests_algobot.dir/clean

CMakeFiles/tests_algobot.dir/depend:
	cd "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases" "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases" "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/build" "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/build" "/home/tomi/Tomi/algo2_tomi/ejercitacion_uso_clases_update (1)/ejercitacion_uso_clases/build/CMakeFiles/tests_algobot.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tests_algobot.dir/depend

