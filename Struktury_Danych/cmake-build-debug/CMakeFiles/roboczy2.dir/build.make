# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/michal/Pobrane/CLion-2017.3.1/clion-2017.3.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/michal/Pobrane/CLion-2017.3.1/clion-2017.3.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michal/CLionProjects/roboczy2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michal/CLionProjects/roboczy2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/roboczy2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roboczy2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roboczy2.dir/flags.make

CMakeFiles/roboczy2.dir/main.cpp.o: CMakeFiles/roboczy2.dir/flags.make
CMakeFiles/roboczy2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michal/CLionProjects/roboczy2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roboczy2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboczy2.dir/main.cpp.o -c /home/michal/CLionProjects/roboczy2/main.cpp

CMakeFiles/roboczy2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboczy2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michal/CLionProjects/roboczy2/main.cpp > CMakeFiles/roboczy2.dir/main.cpp.i

CMakeFiles/roboczy2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboczy2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michal/CLionProjects/roboczy2/main.cpp -o CMakeFiles/roboczy2.dir/main.cpp.s

CMakeFiles/roboczy2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/roboczy2.dir/main.cpp.o.requires

CMakeFiles/roboczy2.dir/main.cpp.o.provides: CMakeFiles/roboczy2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboczy2.dir/build.make CMakeFiles/roboczy2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/roboczy2.dir/main.cpp.o.provides

CMakeFiles/roboczy2.dir/main.cpp.o.provides.build: CMakeFiles/roboczy2.dir/main.cpp.o


CMakeFiles/roboczy2.dir/nowa.cpp.o: CMakeFiles/roboczy2.dir/flags.make
CMakeFiles/roboczy2.dir/nowa.cpp.o: ../nowa.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michal/CLionProjects/roboczy2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/roboczy2.dir/nowa.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roboczy2.dir/nowa.cpp.o -c /home/michal/CLionProjects/roboczy2/nowa.cpp

CMakeFiles/roboczy2.dir/nowa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roboczy2.dir/nowa.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michal/CLionProjects/roboczy2/nowa.cpp > CMakeFiles/roboczy2.dir/nowa.cpp.i

CMakeFiles/roboczy2.dir/nowa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roboczy2.dir/nowa.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michal/CLionProjects/roboczy2/nowa.cpp -o CMakeFiles/roboczy2.dir/nowa.cpp.s

CMakeFiles/roboczy2.dir/nowa.cpp.o.requires:

.PHONY : CMakeFiles/roboczy2.dir/nowa.cpp.o.requires

CMakeFiles/roboczy2.dir/nowa.cpp.o.provides: CMakeFiles/roboczy2.dir/nowa.cpp.o.requires
	$(MAKE) -f CMakeFiles/roboczy2.dir/build.make CMakeFiles/roboczy2.dir/nowa.cpp.o.provides.build
.PHONY : CMakeFiles/roboczy2.dir/nowa.cpp.o.provides

CMakeFiles/roboczy2.dir/nowa.cpp.o.provides.build: CMakeFiles/roboczy2.dir/nowa.cpp.o


# Object files for target roboczy2
roboczy2_OBJECTS = \
"CMakeFiles/roboczy2.dir/main.cpp.o" \
"CMakeFiles/roboczy2.dir/nowa.cpp.o"

# External object files for target roboczy2
roboczy2_EXTERNAL_OBJECTS =

roboczy2: CMakeFiles/roboczy2.dir/main.cpp.o
roboczy2: CMakeFiles/roboczy2.dir/nowa.cpp.o
roboczy2: CMakeFiles/roboczy2.dir/build.make
roboczy2: CMakeFiles/roboczy2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michal/CLionProjects/roboczy2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable roboczy2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roboczy2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roboczy2.dir/build: roboczy2

.PHONY : CMakeFiles/roboczy2.dir/build

CMakeFiles/roboczy2.dir/requires: CMakeFiles/roboczy2.dir/main.cpp.o.requires
CMakeFiles/roboczy2.dir/requires: CMakeFiles/roboczy2.dir/nowa.cpp.o.requires

.PHONY : CMakeFiles/roboczy2.dir/requires

CMakeFiles/roboczy2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/roboczy2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/roboczy2.dir/clean

CMakeFiles/roboczy2.dir/depend:
	cd /home/michal/CLionProjects/roboczy2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michal/CLionProjects/roboczy2 /home/michal/CLionProjects/roboczy2 /home/michal/CLionProjects/roboczy2/cmake-build-debug /home/michal/CLionProjects/roboczy2/cmake-build-debug /home/michal/CLionProjects/roboczy2/cmake-build-debug/CMakeFiles/roboczy2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roboczy2.dir/depend

