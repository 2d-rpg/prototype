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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/build

# Include any dependencies generated for this target.
include CMakeFiles/prototype_libs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prototype_libs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prototype_libs.dir/flags.make

CMakeFiles/prototype_libs.dir/src/glad.c.o: CMakeFiles/prototype_libs.dir/flags.make
CMakeFiles/prototype_libs.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/prototype_libs.dir/src/glad.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prototype_libs.dir/src/glad.c.o   -c /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/src/glad.c

CMakeFiles/prototype_libs.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prototype_libs.dir/src/glad.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/src/glad.c > CMakeFiles/prototype_libs.dir/src/glad.c.i

CMakeFiles/prototype_libs.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prototype_libs.dir/src/glad.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/src/glad.c -o CMakeFiles/prototype_libs.dir/src/glad.c.s

CMakeFiles/prototype_libs.dir/src/utils.cpp.o: CMakeFiles/prototype_libs.dir/flags.make
CMakeFiles/prototype_libs.dir/src/utils.cpp.o: ../src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/prototype_libs.dir/src/utils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prototype_libs.dir/src/utils.cpp.o -c /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/src/utils.cpp

CMakeFiles/prototype_libs.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prototype_libs.dir/src/utils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/src/utils.cpp > CMakeFiles/prototype_libs.dir/src/utils.cpp.i

CMakeFiles/prototype_libs.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prototype_libs.dir/src/utils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/src/utils.cpp -o CMakeFiles/prototype_libs.dir/src/utils.cpp.s

# Object files for target prototype_libs
prototype_libs_OBJECTS = \
"CMakeFiles/prototype_libs.dir/src/glad.c.o" \
"CMakeFiles/prototype_libs.dir/src/utils.cpp.o"

# External object files for target prototype_libs
prototype_libs_EXTERNAL_OBJECTS =

libprototype_libs.a: CMakeFiles/prototype_libs.dir/src/glad.c.o
libprototype_libs.a: CMakeFiles/prototype_libs.dir/src/utils.cpp.o
libprototype_libs.a: CMakeFiles/prototype_libs.dir/build.make
libprototype_libs.a: CMakeFiles/prototype_libs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libprototype_libs.a"
	$(CMAKE_COMMAND) -P CMakeFiles/prototype_libs.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prototype_libs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prototype_libs.dir/build: libprototype_libs.a

.PHONY : CMakeFiles/prototype_libs.dir/build

CMakeFiles/prototype_libs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prototype_libs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prototype_libs.dir/clean

CMakeFiles/prototype_libs.dir/depend:
	cd /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/build /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/build /Users/shibainu/Documents2/GameProjects/2d-rpg/prototype/build/CMakeFiles/prototype_libs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prototype_libs.dir/depend

