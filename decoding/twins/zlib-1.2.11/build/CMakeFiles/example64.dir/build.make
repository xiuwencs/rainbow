# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wudi/code/decoding/twins/zlib-1.2.11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wudi/code/decoding/twins/zlib-1.2.11/build

# Include any dependencies generated for this target.
include CMakeFiles/example64.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/example64.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/example64.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example64.dir/flags.make

CMakeFiles/example64.dir/test/example.o: CMakeFiles/example64.dir/flags.make
CMakeFiles/example64.dir/test/example.o: /home/wudi/code/decoding/twins/zlib-1.2.11/test/example.c
CMakeFiles/example64.dir/test/example.o: CMakeFiles/example64.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wudi/code/decoding/twins/zlib-1.2.11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/example64.dir/test/example.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/example64.dir/test/example.o -MF CMakeFiles/example64.dir/test/example.o.d -o CMakeFiles/example64.dir/test/example.o -c /home/wudi/code/decoding/twins/zlib-1.2.11/test/example.c

CMakeFiles/example64.dir/test/example.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example64.dir/test/example.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wudi/code/decoding/twins/zlib-1.2.11/test/example.c > CMakeFiles/example64.dir/test/example.i

CMakeFiles/example64.dir/test/example.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example64.dir/test/example.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wudi/code/decoding/twins/zlib-1.2.11/test/example.c -o CMakeFiles/example64.dir/test/example.s

# Object files for target example64
example64_OBJECTS = \
"CMakeFiles/example64.dir/test/example.o"

# External object files for target example64
example64_EXTERNAL_OBJECTS =

example64: CMakeFiles/example64.dir/test/example.o
example64: CMakeFiles/example64.dir/build.make
example64: libz.so.1.2.11
example64: CMakeFiles/example64.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wudi/code/decoding/twins/zlib-1.2.11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable example64"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example64.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example64.dir/build: example64
.PHONY : CMakeFiles/example64.dir/build

CMakeFiles/example64.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example64.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example64.dir/clean

CMakeFiles/example64.dir/depend:
	cd /home/wudi/code/decoding/twins/zlib-1.2.11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wudi/code/decoding/twins/zlib-1.2.11 /home/wudi/code/decoding/twins/zlib-1.2.11 /home/wudi/code/decoding/twins/zlib-1.2.11/build /home/wudi/code/decoding/twins/zlib-1.2.11/build /home/wudi/code/decoding/twins/zlib-1.2.11/build/CMakeFiles/example64.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example64.dir/depend

