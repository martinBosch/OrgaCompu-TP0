# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/share/clion-2016.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/share/clion-2016.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tg/FIUBA/orga6620/tp0/app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/main.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/main.c.o   -c /home/tg/FIUBA/orga6620/tp0/app/main.c

CMakeFiles/app.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/orga6620/tp0/app/main.c > CMakeFiles/app.dir/main.c.i

CMakeFiles/app.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/orga6620/tp0/app/main.c -o CMakeFiles/app.dir/main.c.s

CMakeFiles/app.dir/main.c.o.requires:

.PHONY : CMakeFiles/app.dir/main.c.o.requires

CMakeFiles/app.dir/main.c.o.provides: CMakeFiles/app.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/app.dir/build.make CMakeFiles/app.dir/main.c.o.provides.build
.PHONY : CMakeFiles/app.dir/main.c.o.provides

CMakeFiles/app.dir/main.c.o.provides.build: CMakeFiles/app.dir/main.c.o


CMakeFiles/app.dir/buffer.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/buffer.c.o: ../buffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/app.dir/buffer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/buffer.c.o   -c /home/tg/FIUBA/orga6620/tp0/app/buffer.c

CMakeFiles/app.dir/buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/buffer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/orga6620/tp0/app/buffer.c > CMakeFiles/app.dir/buffer.c.i

CMakeFiles/app.dir/buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/buffer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/orga6620/tp0/app/buffer.c -o CMakeFiles/app.dir/buffer.c.s

CMakeFiles/app.dir/buffer.c.o.requires:

.PHONY : CMakeFiles/app.dir/buffer.c.o.requires

CMakeFiles/app.dir/buffer.c.o.provides: CMakeFiles/app.dir/buffer.c.o.requires
	$(MAKE) -f CMakeFiles/app.dir/build.make CMakeFiles/app.dir/buffer.c.o.provides.build
.PHONY : CMakeFiles/app.dir/buffer.c.o.provides

CMakeFiles/app.dir/buffer.c.o.provides.build: CMakeFiles/app.dir/buffer.c.o


CMakeFiles/app.dir/ordenamiento.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/ordenamiento.c.o: ../ordenamiento.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/app.dir/ordenamiento.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/ordenamiento.c.o   -c /home/tg/FIUBA/orga6620/tp0/app/ordenamiento.c

CMakeFiles/app.dir/ordenamiento.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/ordenamiento.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/orga6620/tp0/app/ordenamiento.c > CMakeFiles/app.dir/ordenamiento.c.i

CMakeFiles/app.dir/ordenamiento.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/ordenamiento.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/orga6620/tp0/app/ordenamiento.c -o CMakeFiles/app.dir/ordenamiento.c.s

CMakeFiles/app.dir/ordenamiento.c.o.requires:

.PHONY : CMakeFiles/app.dir/ordenamiento.c.o.requires

CMakeFiles/app.dir/ordenamiento.c.o.provides: CMakeFiles/app.dir/ordenamiento.c.o.requires
	$(MAKE) -f CMakeFiles/app.dir/build.make CMakeFiles/app.dir/ordenamiento.c.o.provides.build
.PHONY : CMakeFiles/app.dir/ordenamiento.c.o.provides

CMakeFiles/app.dir/ordenamiento.c.o.provides.build: CMakeFiles/app.dir/ordenamiento.c.o


CMakeFiles/app.dir/wordlist.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/wordlist.c.o: ../wordlist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/app.dir/wordlist.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/wordlist.c.o   -c /home/tg/FIUBA/orga6620/tp0/app/wordlist.c

CMakeFiles/app.dir/wordlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/wordlist.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/orga6620/tp0/app/wordlist.c > CMakeFiles/app.dir/wordlist.c.i

CMakeFiles/app.dir/wordlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/wordlist.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/orga6620/tp0/app/wordlist.c -o CMakeFiles/app.dir/wordlist.c.s

CMakeFiles/app.dir/wordlist.c.o.requires:

.PHONY : CMakeFiles/app.dir/wordlist.c.o.requires

CMakeFiles/app.dir/wordlist.c.o.provides: CMakeFiles/app.dir/wordlist.c.o.requires
	$(MAKE) -f CMakeFiles/app.dir/build.make CMakeFiles/app.dir/wordlist.c.o.provides.build
.PHONY : CMakeFiles/app.dir/wordlist.c.o.provides

CMakeFiles/app.dir/wordlist.c.o.provides.build: CMakeFiles/app.dir/wordlist.c.o


# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/main.c.o" \
"CMakeFiles/app.dir/buffer.c.o" \
"CMakeFiles/app.dir/ordenamiento.c.o" \
"CMakeFiles/app.dir/wordlist.c.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/main.c.o
app: CMakeFiles/app.dir/buffer.c.o
app: CMakeFiles/app.dir/ordenamiento.c.o
app: CMakeFiles/app.dir/wordlist.c.o
app: CMakeFiles/app.dir/build.make
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app

.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/requires: CMakeFiles/app.dir/main.c.o.requires
CMakeFiles/app.dir/requires: CMakeFiles/app.dir/buffer.c.o.requires
CMakeFiles/app.dir/requires: CMakeFiles/app.dir/ordenamiento.c.o.requires
CMakeFiles/app.dir/requires: CMakeFiles/app.dir/wordlist.c.o.requires

.PHONY : CMakeFiles/app.dir/requires

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tg/FIUBA/orga6620/tp0/app /home/tg/FIUBA/orga6620/tp0/app /home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug /home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug /home/tg/FIUBA/orga6620/tp0/app/cmake-build-debug/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend

