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
CMAKE_SOURCE_DIR = /home/wudi/code/decoding/rainbow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wudi/code/decoding/rainbow/build

# Include any dependencies generated for this target.
include CMakeFiles/brotlicommon-static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/brotlicommon-static.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/brotlicommon-static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/brotlicommon-static.dir/flags.make

CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o: CMakeFiles/brotlicommon-static.dir/flags.make
CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o: /home/wudi/code/decoding/rainbow/c/common/constants.c
CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o: CMakeFiles/brotlicommon-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wudi/code/decoding/rainbow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o -MF CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o.d -o CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o -c /home/wudi/code/decoding/rainbow/c/common/constants.c

CMakeFiles/brotlicommon-static.dir/c/common/constants.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/brotlicommon-static.dir/c/common/constants.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wudi/code/decoding/rainbow/c/common/constants.c > CMakeFiles/brotlicommon-static.dir/c/common/constants.c.i

CMakeFiles/brotlicommon-static.dir/c/common/constants.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/brotlicommon-static.dir/c/common/constants.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wudi/code/decoding/rainbow/c/common/constants.c -o CMakeFiles/brotlicommon-static.dir/c/common/constants.c.s

CMakeFiles/brotlicommon-static.dir/c/common/context.c.o: CMakeFiles/brotlicommon-static.dir/flags.make
CMakeFiles/brotlicommon-static.dir/c/common/context.c.o: /home/wudi/code/decoding/rainbow/c/common/context.c
CMakeFiles/brotlicommon-static.dir/c/common/context.c.o: CMakeFiles/brotlicommon-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wudi/code/decoding/rainbow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/brotlicommon-static.dir/c/common/context.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/brotlicommon-static.dir/c/common/context.c.o -MF CMakeFiles/brotlicommon-static.dir/c/common/context.c.o.d -o CMakeFiles/brotlicommon-static.dir/c/common/context.c.o -c /home/wudi/code/decoding/rainbow/c/common/context.c

CMakeFiles/brotlicommon-static.dir/c/common/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/brotlicommon-static.dir/c/common/context.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wudi/code/decoding/rainbow/c/common/context.c > CMakeFiles/brotlicommon-static.dir/c/common/context.c.i

CMakeFiles/brotlicommon-static.dir/c/common/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/brotlicommon-static.dir/c/common/context.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wudi/code/decoding/rainbow/c/common/context.c -o CMakeFiles/brotlicommon-static.dir/c/common/context.c.s

CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o: CMakeFiles/brotlicommon-static.dir/flags.make
CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o: /home/wudi/code/decoding/rainbow/c/common/dictionary.c
CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o: CMakeFiles/brotlicommon-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wudi/code/decoding/rainbow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o -MF CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o.d -o CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o -c /home/wudi/code/decoding/rainbow/c/common/dictionary.c

CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wudi/code/decoding/rainbow/c/common/dictionary.c > CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.i

CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wudi/code/decoding/rainbow/c/common/dictionary.c -o CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.s

CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o: CMakeFiles/brotlicommon-static.dir/flags.make
CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o: /home/wudi/code/decoding/rainbow/c/common/platform.c
CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o: CMakeFiles/brotlicommon-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wudi/code/decoding/rainbow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o -MF CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o.d -o CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o -c /home/wudi/code/decoding/rainbow/c/common/platform.c

CMakeFiles/brotlicommon-static.dir/c/common/platform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/brotlicommon-static.dir/c/common/platform.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wudi/code/decoding/rainbow/c/common/platform.c > CMakeFiles/brotlicommon-static.dir/c/common/platform.c.i

CMakeFiles/brotlicommon-static.dir/c/common/platform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/brotlicommon-static.dir/c/common/platform.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wudi/code/decoding/rainbow/c/common/platform.c -o CMakeFiles/brotlicommon-static.dir/c/common/platform.c.s

CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o: CMakeFiles/brotlicommon-static.dir/flags.make
CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o: /home/wudi/code/decoding/rainbow/c/common/transform.c
CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o: CMakeFiles/brotlicommon-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wudi/code/decoding/rainbow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o -MF CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o.d -o CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o -c /home/wudi/code/decoding/rainbow/c/common/transform.c

CMakeFiles/brotlicommon-static.dir/c/common/transform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/brotlicommon-static.dir/c/common/transform.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wudi/code/decoding/rainbow/c/common/transform.c > CMakeFiles/brotlicommon-static.dir/c/common/transform.c.i

CMakeFiles/brotlicommon-static.dir/c/common/transform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/brotlicommon-static.dir/c/common/transform.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wudi/code/decoding/rainbow/c/common/transform.c -o CMakeFiles/brotlicommon-static.dir/c/common/transform.c.s

# Object files for target brotlicommon-static
brotlicommon__static_OBJECTS = \
"CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o" \
"CMakeFiles/brotlicommon-static.dir/c/common/context.c.o" \
"CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o" \
"CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o" \
"CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o"

# External object files for target brotlicommon-static
brotlicommon__static_EXTERNAL_OBJECTS =

libbrotlicommon-static.a: CMakeFiles/brotlicommon-static.dir/c/common/constants.c.o
libbrotlicommon-static.a: CMakeFiles/brotlicommon-static.dir/c/common/context.c.o
libbrotlicommon-static.a: CMakeFiles/brotlicommon-static.dir/c/common/dictionary.c.o
libbrotlicommon-static.a: CMakeFiles/brotlicommon-static.dir/c/common/platform.c.o
libbrotlicommon-static.a: CMakeFiles/brotlicommon-static.dir/c/common/transform.c.o
libbrotlicommon-static.a: CMakeFiles/brotlicommon-static.dir/build.make
libbrotlicommon-static.a: CMakeFiles/brotlicommon-static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wudi/code/decoding/rainbow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libbrotlicommon-static.a"
	$(CMAKE_COMMAND) -P CMakeFiles/brotlicommon-static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/brotlicommon-static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/brotlicommon-static.dir/build: libbrotlicommon-static.a
.PHONY : CMakeFiles/brotlicommon-static.dir/build

CMakeFiles/brotlicommon-static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/brotlicommon-static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/brotlicommon-static.dir/clean

CMakeFiles/brotlicommon-static.dir/depend:
	cd /home/wudi/code/decoding/rainbow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wudi/code/decoding/rainbow /home/wudi/code/decoding/rainbow /home/wudi/code/decoding/rainbow/build /home/wudi/code/decoding/rainbow/build /home/wudi/code/decoding/rainbow/build/CMakeFiles/brotlicommon-static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/brotlicommon-static.dir/depend

