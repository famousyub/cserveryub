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
CMAKE_SOURCE_DIR = /home/user/Bureau/atmproject/moquito/crcpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Bureau/atmproject/moquito/crcpp/bin

# Include any dependencies generated for this target.
include models/CMakeFiles/user_permission.dir/depend.make

# Include the progress variables for this target.
include models/CMakeFiles/user_permission.dir/progress.make

# Include the compile flags for this target's objects.
include models/CMakeFiles/user_permission.dir/flags.make

models/CMakeFiles/user_permission.dir/user_permission.cpp.o: models/CMakeFiles/user_permission.dir/flags.make
models/CMakeFiles/user_permission.dir/user_permission.cpp.o: ../models/user_permission.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Bureau/atmproject/moquito/crcpp/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object models/CMakeFiles/user_permission.dir/user_permission.cpp.o"
	cd /home/user/Bureau/atmproject/moquito/crcpp/bin/models && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user_permission.dir/user_permission.cpp.o -c /home/user/Bureau/atmproject/moquito/crcpp/models/user_permission.cpp

models/CMakeFiles/user_permission.dir/user_permission.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_permission.dir/user_permission.cpp.i"
	cd /home/user/Bureau/atmproject/moquito/crcpp/bin/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Bureau/atmproject/moquito/crcpp/models/user_permission.cpp > CMakeFiles/user_permission.dir/user_permission.cpp.i

models/CMakeFiles/user_permission.dir/user_permission.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_permission.dir/user_permission.cpp.s"
	cd /home/user/Bureau/atmproject/moquito/crcpp/bin/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Bureau/atmproject/moquito/crcpp/models/user_permission.cpp -o CMakeFiles/user_permission.dir/user_permission.cpp.s

# Object files for target user_permission
user_permission_OBJECTS = \
"CMakeFiles/user_permission.dir/user_permission.cpp.o"

# External object files for target user_permission
user_permission_EXTERNAL_OBJECTS =

models/libuser_permission.a: models/CMakeFiles/user_permission.dir/user_permission.cpp.o
models/libuser_permission.a: models/CMakeFiles/user_permission.dir/build.make
models/libuser_permission.a: models/CMakeFiles/user_permission.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Bureau/atmproject/moquito/crcpp/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libuser_permission.a"
	cd /home/user/Bureau/atmproject/moquito/crcpp/bin/models && $(CMAKE_COMMAND) -P CMakeFiles/user_permission.dir/cmake_clean_target.cmake
	cd /home/user/Bureau/atmproject/moquito/crcpp/bin/models && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/user_permission.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
models/CMakeFiles/user_permission.dir/build: models/libuser_permission.a

.PHONY : models/CMakeFiles/user_permission.dir/build

models/CMakeFiles/user_permission.dir/clean:
	cd /home/user/Bureau/atmproject/moquito/crcpp/bin/models && $(CMAKE_COMMAND) -P CMakeFiles/user_permission.dir/cmake_clean.cmake
.PHONY : models/CMakeFiles/user_permission.dir/clean

models/CMakeFiles/user_permission.dir/depend:
	cd /home/user/Bureau/atmproject/moquito/crcpp/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Bureau/atmproject/moquito/crcpp /home/user/Bureau/atmproject/moquito/crcpp/models /home/user/Bureau/atmproject/moquito/crcpp/bin /home/user/Bureau/atmproject/moquito/crcpp/bin/models /home/user/Bureau/atmproject/moquito/crcpp/bin/models/CMakeFiles/user_permission.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : models/CMakeFiles/user_permission.dir/depend

