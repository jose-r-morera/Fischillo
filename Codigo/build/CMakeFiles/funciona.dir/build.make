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
CMAKE_SOURCE_DIR = /home/jr/Desktop/SmartLock/Codigo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jr/Desktop/SmartLock/Codigo/build

# Include any dependencies generated for this target.
include CMakeFiles/funciona.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/funciona.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/funciona.dir/flags.make

CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.o: CMakeFiles/funciona.dir/flags.make
CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.o: ../src/cerradura_inteligente.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc

CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc > CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.i

CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc -o CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.s

CMakeFiles/funciona.dir/src/usuario.cc.o: CMakeFiles/funciona.dir/flags.make
CMakeFiles/funciona.dir/src/usuario.cc.o: ../src/usuario.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/funciona.dir/src/usuario.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/funciona.dir/src/usuario.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc

CMakeFiles/funciona.dir/src/usuario.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/funciona.dir/src/usuario.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc > CMakeFiles/funciona.dir/src/usuario.cc.i

CMakeFiles/funciona.dir/src/usuario.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/funciona.dir/src/usuario.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc -o CMakeFiles/funciona.dir/src/usuario.cc.s

CMakeFiles/funciona.dir/src/base_datos.cc.o: CMakeFiles/funciona.dir/flags.make
CMakeFiles/funciona.dir/src/base_datos.cc.o: ../src/base_datos.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/funciona.dir/src/base_datos.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/funciona.dir/src/base_datos.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc

CMakeFiles/funciona.dir/src/base_datos.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/funciona.dir/src/base_datos.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc > CMakeFiles/funciona.dir/src/base_datos.cc.i

CMakeFiles/funciona.dir/src/base_datos.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/funciona.dir/src/base_datos.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc -o CMakeFiles/funciona.dir/src/base_datos.cc.s

CMakeFiles/funciona.dir/src/funciona.cc.o: CMakeFiles/funciona.dir/flags.make
CMakeFiles/funciona.dir/src/funciona.cc.o: ../src/funciona.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/funciona.dir/src/funciona.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/funciona.dir/src/funciona.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/funciona.cc

CMakeFiles/funciona.dir/src/funciona.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/funciona.dir/src/funciona.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/funciona.cc > CMakeFiles/funciona.dir/src/funciona.cc.i

CMakeFiles/funciona.dir/src/funciona.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/funciona.dir/src/funciona.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/funciona.cc -o CMakeFiles/funciona.dir/src/funciona.cc.s

# Object files for target funciona
funciona_OBJECTS = \
"CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.o" \
"CMakeFiles/funciona.dir/src/usuario.cc.o" \
"CMakeFiles/funciona.dir/src/base_datos.cc.o" \
"CMakeFiles/funciona.dir/src/funciona.cc.o"

# External object files for target funciona
funciona_EXTERNAL_OBJECTS =

funciona: CMakeFiles/funciona.dir/src/cerradura_inteligente.cc.o
funciona: CMakeFiles/funciona.dir/src/usuario.cc.o
funciona: CMakeFiles/funciona.dir/src/base_datos.cc.o
funciona: CMakeFiles/funciona.dir/src/funciona.cc.o
funciona: CMakeFiles/funciona.dir/build.make
funciona: CMakeFiles/funciona.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable funciona"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/funciona.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/funciona.dir/build: funciona

.PHONY : CMakeFiles/funciona.dir/build

CMakeFiles/funciona.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/funciona.dir/cmake_clean.cmake
.PHONY : CMakeFiles/funciona.dir/clean

CMakeFiles/funciona.dir/depend:
	cd /home/jr/Desktop/SmartLock/Codigo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jr/Desktop/SmartLock/Codigo /home/jr/Desktop/SmartLock/Codigo /home/jr/Desktop/SmartLock/Codigo/build /home/jr/Desktop/SmartLock/Codigo/build /home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles/funciona.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/funciona.dir/depend

