# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ubuntu2204/桌面/cmakeVersion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu2204/桌面/cmakeVersion

# Include any dependencies generated for this target.
include CMakeFiles/LogExe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LogExe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LogExe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LogExe.dir/flags.make

CMakeFiles/LogExe.dir/main.cpp.o: CMakeFiles/LogExe.dir/flags.make
CMakeFiles/LogExe.dir/main.cpp.o: main.cpp
CMakeFiles/LogExe.dir/main.cpp.o: CMakeFiles/LogExe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/cmakeVersion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LogExe.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LogExe.dir/main.cpp.o -MF CMakeFiles/LogExe.dir/main.cpp.o.d -o CMakeFiles/LogExe.dir/main.cpp.o -c /home/ubuntu2204/桌面/cmakeVersion/main.cpp

CMakeFiles/LogExe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogExe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/cmakeVersion/main.cpp > CMakeFiles/LogExe.dir/main.cpp.i

CMakeFiles/LogExe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogExe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/cmakeVersion/main.cpp -o CMakeFiles/LogExe.dir/main.cpp.s

CMakeFiles/LogExe.dir/src/easylogging++.cc.o: CMakeFiles/LogExe.dir/flags.make
CMakeFiles/LogExe.dir/src/easylogging++.cc.o: src/easylogging++.cc
CMakeFiles/LogExe.dir/src/easylogging++.cc.o: CMakeFiles/LogExe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/cmakeVersion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LogExe.dir/src/easylogging++.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LogExe.dir/src/easylogging++.cc.o -MF CMakeFiles/LogExe.dir/src/easylogging++.cc.o.d -o CMakeFiles/LogExe.dir/src/easylogging++.cc.o -c /home/ubuntu2204/桌面/cmakeVersion/src/easylogging++.cc

CMakeFiles/LogExe.dir/src/easylogging++.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogExe.dir/src/easylogging++.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/cmakeVersion/src/easylogging++.cc > CMakeFiles/LogExe.dir/src/easylogging++.cc.i

CMakeFiles/LogExe.dir/src/easylogging++.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogExe.dir/src/easylogging++.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/cmakeVersion/src/easylogging++.cc -o CMakeFiles/LogExe.dir/src/easylogging++.cc.s

# Object files for target LogExe
LogExe_OBJECTS = \
"CMakeFiles/LogExe.dir/main.cpp.o" \
"CMakeFiles/LogExe.dir/src/easylogging++.cc.o"

# External object files for target LogExe
LogExe_EXTERNAL_OBJECTS =

LogExe: CMakeFiles/LogExe.dir/main.cpp.o
LogExe: CMakeFiles/LogExe.dir/src/easylogging++.cc.o
LogExe: CMakeFiles/LogExe.dir/build.make
LogExe: CMakeFiles/LogExe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu2204/桌面/cmakeVersion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LogExe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LogExe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LogExe.dir/build: LogExe
.PHONY : CMakeFiles/LogExe.dir/build

CMakeFiles/LogExe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LogExe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LogExe.dir/clean

CMakeFiles/LogExe.dir/depend:
	cd /home/ubuntu2204/桌面/cmakeVersion && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu2204/桌面/cmakeVersion /home/ubuntu2204/桌面/cmakeVersion /home/ubuntu2204/桌面/cmakeVersion /home/ubuntu2204/桌面/cmakeVersion /home/ubuntu2204/桌面/cmakeVersion/CMakeFiles/LogExe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LogExe.dir/depend
