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
CMAKE_SOURCE_DIR = /home/ubuntu2204/桌面/classroom-base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu2204/桌面/classroom-base

# Include any dependencies generated for this target.
include CMakeFiles/base_static_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/base_static_library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/base_static_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/base_static_library.dir/flags.make

CMakeFiles/base_static_library.dir/src/Condition.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/Condition.cc.o: src/Condition.cc
CMakeFiles/base_static_library.dir/src/Condition.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/base_static_library.dir/src/Condition.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/Condition.cc.o -MF CMakeFiles/base_static_library.dir/src/Condition.cc.o.d -o CMakeFiles/base_static_library.dir/src/Condition.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/Condition.cc

CMakeFiles/base_static_library.dir/src/Condition.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/Condition.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/Condition.cc > CMakeFiles/base_static_library.dir/src/Condition.cc.i

CMakeFiles/base_static_library.dir/src/Condition.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/Condition.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/Condition.cc -o CMakeFiles/base_static_library.dir/src/Condition.cc.s

CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o: src/CountDownLatch.cc
CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o -MF CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o.d -o CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/CountDownLatch.cc

CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/CountDownLatch.cc > CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.i

CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/CountDownLatch.cc -o CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.s

CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o: src/CurrentThread.cc
CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o -MF CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o.d -o CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/CurrentThread.cc

CMakeFiles/base_static_library.dir/src/CurrentThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/CurrentThread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/CurrentThread.cc > CMakeFiles/base_static_library.dir/src/CurrentThread.cc.i

CMakeFiles/base_static_library.dir/src/CurrentThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/CurrentThread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/CurrentThread.cc -o CMakeFiles/base_static_library.dir/src/CurrentThread.cc.s

CMakeFiles/base_static_library.dir/src/Date.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/Date.cc.o: src/Date.cc
CMakeFiles/base_static_library.dir/src/Date.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/base_static_library.dir/src/Date.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/Date.cc.o -MF CMakeFiles/base_static_library.dir/src/Date.cc.o.d -o CMakeFiles/base_static_library.dir/src/Date.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/Date.cc

CMakeFiles/base_static_library.dir/src/Date.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/Date.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/Date.cc > CMakeFiles/base_static_library.dir/src/Date.cc.i

CMakeFiles/base_static_library.dir/src/Date.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/Date.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/Date.cc -o CMakeFiles/base_static_library.dir/src/Date.cc.s

CMakeFiles/base_static_library.dir/src/Exception.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/Exception.cc.o: src/Exception.cc
CMakeFiles/base_static_library.dir/src/Exception.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/base_static_library.dir/src/Exception.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/Exception.cc.o -MF CMakeFiles/base_static_library.dir/src/Exception.cc.o.d -o CMakeFiles/base_static_library.dir/src/Exception.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/Exception.cc

CMakeFiles/base_static_library.dir/src/Exception.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/Exception.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/Exception.cc > CMakeFiles/base_static_library.dir/src/Exception.cc.i

CMakeFiles/base_static_library.dir/src/Exception.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/Exception.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/Exception.cc -o CMakeFiles/base_static_library.dir/src/Exception.cc.s

CMakeFiles/base_static_library.dir/src/FileUtil.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/FileUtil.cc.o: src/FileUtil.cc
CMakeFiles/base_static_library.dir/src/FileUtil.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/base_static_library.dir/src/FileUtil.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/FileUtil.cc.o -MF CMakeFiles/base_static_library.dir/src/FileUtil.cc.o.d -o CMakeFiles/base_static_library.dir/src/FileUtil.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/FileUtil.cc

CMakeFiles/base_static_library.dir/src/FileUtil.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/FileUtil.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/FileUtil.cc > CMakeFiles/base_static_library.dir/src/FileUtil.cc.i

CMakeFiles/base_static_library.dir/src/FileUtil.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/FileUtil.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/FileUtil.cc -o CMakeFiles/base_static_library.dir/src/FileUtil.cc.s

CMakeFiles/base_static_library.dir/src/LogFile.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/LogFile.cc.o: src/LogFile.cc
CMakeFiles/base_static_library.dir/src/LogFile.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/base_static_library.dir/src/LogFile.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/LogFile.cc.o -MF CMakeFiles/base_static_library.dir/src/LogFile.cc.o.d -o CMakeFiles/base_static_library.dir/src/LogFile.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/LogFile.cc

CMakeFiles/base_static_library.dir/src/LogFile.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/LogFile.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/LogFile.cc > CMakeFiles/base_static_library.dir/src/LogFile.cc.i

CMakeFiles/base_static_library.dir/src/LogFile.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/LogFile.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/LogFile.cc -o CMakeFiles/base_static_library.dir/src/LogFile.cc.s

CMakeFiles/base_static_library.dir/src/Logging.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/Logging.cc.o: src/Logging.cc
CMakeFiles/base_static_library.dir/src/Logging.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/base_static_library.dir/src/Logging.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/Logging.cc.o -MF CMakeFiles/base_static_library.dir/src/Logging.cc.o.d -o CMakeFiles/base_static_library.dir/src/Logging.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/Logging.cc

CMakeFiles/base_static_library.dir/src/Logging.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/Logging.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/Logging.cc > CMakeFiles/base_static_library.dir/src/Logging.cc.i

CMakeFiles/base_static_library.dir/src/Logging.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/Logging.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/Logging.cc -o CMakeFiles/base_static_library.dir/src/Logging.cc.s

CMakeFiles/base_static_library.dir/src/LogStream.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/LogStream.cc.o: src/LogStream.cc
CMakeFiles/base_static_library.dir/src/LogStream.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/base_static_library.dir/src/LogStream.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/LogStream.cc.o -MF CMakeFiles/base_static_library.dir/src/LogStream.cc.o.d -o CMakeFiles/base_static_library.dir/src/LogStream.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/LogStream.cc

CMakeFiles/base_static_library.dir/src/LogStream.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/LogStream.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/LogStream.cc > CMakeFiles/base_static_library.dir/src/LogStream.cc.i

CMakeFiles/base_static_library.dir/src/LogStream.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/LogStream.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/LogStream.cc -o CMakeFiles/base_static_library.dir/src/LogStream.cc.s

CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o: src/ProcessInfo.cc
CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o -MF CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o.d -o CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/ProcessInfo.cc

CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/ProcessInfo.cc > CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.i

CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/ProcessInfo.cc -o CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.s

CMakeFiles/base_static_library.dir/src/Thread.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/Thread.cc.o: src/Thread.cc
CMakeFiles/base_static_library.dir/src/Thread.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/base_static_library.dir/src/Thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/Thread.cc.o -MF CMakeFiles/base_static_library.dir/src/Thread.cc.o.d -o CMakeFiles/base_static_library.dir/src/Thread.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/Thread.cc

CMakeFiles/base_static_library.dir/src/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/Thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/Thread.cc > CMakeFiles/base_static_library.dir/src/Thread.cc.i

CMakeFiles/base_static_library.dir/src/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/Thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/Thread.cc -o CMakeFiles/base_static_library.dir/src/Thread.cc.s

CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o: src/ThreadPool.cc
CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o -MF CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o.d -o CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/ThreadPool.cc

CMakeFiles/base_static_library.dir/src/ThreadPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/ThreadPool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/ThreadPool.cc > CMakeFiles/base_static_library.dir/src/ThreadPool.cc.i

CMakeFiles/base_static_library.dir/src/ThreadPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/ThreadPool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/ThreadPool.cc -o CMakeFiles/base_static_library.dir/src/ThreadPool.cc.s

CMakeFiles/base_static_library.dir/src/TimeZone.cc.o: CMakeFiles/base_static_library.dir/flags.make
CMakeFiles/base_static_library.dir/src/TimeZone.cc.o: src/TimeZone.cc
CMakeFiles/base_static_library.dir/src/TimeZone.cc.o: CMakeFiles/base_static_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/base_static_library.dir/src/TimeZone.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_static_library.dir/src/TimeZone.cc.o -MF CMakeFiles/base_static_library.dir/src/TimeZone.cc.o.d -o CMakeFiles/base_static_library.dir/src/TimeZone.cc.o -c /home/ubuntu2204/桌面/classroom-base/src/TimeZone.cc

CMakeFiles/base_static_library.dir/src/TimeZone.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_static_library.dir/src/TimeZone.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu2204/桌面/classroom-base/src/TimeZone.cc > CMakeFiles/base_static_library.dir/src/TimeZone.cc.i

CMakeFiles/base_static_library.dir/src/TimeZone.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_static_library.dir/src/TimeZone.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu2204/桌面/classroom-base/src/TimeZone.cc -o CMakeFiles/base_static_library.dir/src/TimeZone.cc.s

# Object files for target base_static_library
base_static_library_OBJECTS = \
"CMakeFiles/base_static_library.dir/src/Condition.cc.o" \
"CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o" \
"CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o" \
"CMakeFiles/base_static_library.dir/src/Date.cc.o" \
"CMakeFiles/base_static_library.dir/src/Exception.cc.o" \
"CMakeFiles/base_static_library.dir/src/FileUtil.cc.o" \
"CMakeFiles/base_static_library.dir/src/LogFile.cc.o" \
"CMakeFiles/base_static_library.dir/src/Logging.cc.o" \
"CMakeFiles/base_static_library.dir/src/LogStream.cc.o" \
"CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o" \
"CMakeFiles/base_static_library.dir/src/Thread.cc.o" \
"CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o" \
"CMakeFiles/base_static_library.dir/src/TimeZone.cc.o"

# External object files for target base_static_library
base_static_library_EXTERNAL_OBJECTS =

libbase_static_library.a: CMakeFiles/base_static_library.dir/src/Condition.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/CountDownLatch.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/CurrentThread.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/Date.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/Exception.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/FileUtil.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/LogFile.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/Logging.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/LogStream.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/ProcessInfo.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/Thread.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/ThreadPool.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/src/TimeZone.cc.o
libbase_static_library.a: CMakeFiles/base_static_library.dir/build.make
libbase_static_library.a: CMakeFiles/base_static_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu2204/桌面/classroom-base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX static library libbase_static_library.a"
	$(CMAKE_COMMAND) -P CMakeFiles/base_static_library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base_static_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/base_static_library.dir/build: libbase_static_library.a
.PHONY : CMakeFiles/base_static_library.dir/build

CMakeFiles/base_static_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/base_static_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/base_static_library.dir/clean

CMakeFiles/base_static_library.dir/depend:
	cd /home/ubuntu2204/桌面/classroom-base && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu2204/桌面/classroom-base /home/ubuntu2204/桌面/classroom-base /home/ubuntu2204/桌面/classroom-base /home/ubuntu2204/桌面/classroom-base /home/ubuntu2204/桌面/classroom-base/CMakeFiles/base_static_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/base_static_library.dir/depend

