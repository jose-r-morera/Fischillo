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
include CMakeFiles/fischillo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fischillo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fischillo.dir/flags.make

CMakeFiles/fischillo.dir/src/cliente.cc.o: CMakeFiles/fischillo.dir/flags.make
CMakeFiles/fischillo.dir/src/cliente.cc.o: ../src/cliente.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fischillo.dir/src/cliente.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fischillo.dir/src/cliente.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/cliente.cc

CMakeFiles/fischillo.dir/src/cliente.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fischillo.dir/src/cliente.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/cliente.cc > CMakeFiles/fischillo.dir/src/cliente.cc.i

CMakeFiles/fischillo.dir/src/cliente.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fischillo.dir/src/cliente.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/cliente.cc -o CMakeFiles/fischillo.dir/src/cliente.cc.s

CMakeFiles/fischillo.dir/src/cliente_funciones.cc.o: CMakeFiles/fischillo.dir/flags.make
CMakeFiles/fischillo.dir/src/cliente_funciones.cc.o: ../src/cliente_funciones.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fischillo.dir/src/cliente_funciones.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fischillo.dir/src/cliente_funciones.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/cliente_funciones.cc

CMakeFiles/fischillo.dir/src/cliente_funciones.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fischillo.dir/src/cliente_funciones.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/cliente_funciones.cc > CMakeFiles/fischillo.dir/src/cliente_funciones.cc.i

CMakeFiles/fischillo.dir/src/cliente_funciones.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fischillo.dir/src/cliente_funciones.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/cliente_funciones.cc -o CMakeFiles/fischillo.dir/src/cliente_funciones.cc.s

CMakeFiles/fischillo.dir/src/identificacion.cc.o: CMakeFiles/fischillo.dir/flags.make
CMakeFiles/fischillo.dir/src/identificacion.cc.o: ../src/identificacion.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fischillo.dir/src/identificacion.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fischillo.dir/src/identificacion.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/identificacion.cc

CMakeFiles/fischillo.dir/src/identificacion.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fischillo.dir/src/identificacion.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/identificacion.cc > CMakeFiles/fischillo.dir/src/identificacion.cc.i

CMakeFiles/fischillo.dir/src/identificacion.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fischillo.dir/src/identificacion.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/identificacion.cc -o CMakeFiles/fischillo.dir/src/identificacion.cc.s

CMakeFiles/fischillo.dir/src/base_datos.cc.o: CMakeFiles/fischillo.dir/flags.make
CMakeFiles/fischillo.dir/src/base_datos.cc.o: ../src/base_datos.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fischillo.dir/src/base_datos.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fischillo.dir/src/base_datos.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc

CMakeFiles/fischillo.dir/src/base_datos.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fischillo.dir/src/base_datos.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc > CMakeFiles/fischillo.dir/src/base_datos.cc.i

CMakeFiles/fischillo.dir/src/base_datos.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fischillo.dir/src/base_datos.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc -o CMakeFiles/fischillo.dir/src/base_datos.cc.s

CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.o: CMakeFiles/fischillo.dir/flags.make
CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.o: ../src/cerradura_inteligente.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc

CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc > CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.i

CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc -o CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.s

CMakeFiles/fischillo.dir/src/usuario.cc.o: CMakeFiles/fischillo.dir/flags.make
CMakeFiles/fischillo.dir/src/usuario.cc.o: ../src/usuario.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/fischillo.dir/src/usuario.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fischillo.dir/src/usuario.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc

CMakeFiles/fischillo.dir/src/usuario.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fischillo.dir/src/usuario.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc > CMakeFiles/fischillo.dir/src/usuario.cc.i

CMakeFiles/fischillo.dir/src/usuario.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fischillo.dir/src/usuario.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc -o CMakeFiles/fischillo.dir/src/usuario.cc.s

# Object files for target fischillo
fischillo_OBJECTS = \
"CMakeFiles/fischillo.dir/src/cliente.cc.o" \
"CMakeFiles/fischillo.dir/src/cliente_funciones.cc.o" \
"CMakeFiles/fischillo.dir/src/identificacion.cc.o" \
"CMakeFiles/fischillo.dir/src/base_datos.cc.o" \
"CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.o" \
"CMakeFiles/fischillo.dir/src/usuario.cc.o"

# External object files for target fischillo
fischillo_EXTERNAL_OBJECTS =

fischillo: CMakeFiles/fischillo.dir/src/cliente.cc.o
fischillo: CMakeFiles/fischillo.dir/src/cliente_funciones.cc.o
fischillo: CMakeFiles/fischillo.dir/src/identificacion.cc.o
fischillo: CMakeFiles/fischillo.dir/src/base_datos.cc.o
fischillo: CMakeFiles/fischillo.dir/src/cerradura_inteligente.cc.o
fischillo: CMakeFiles/fischillo.dir/src/usuario.cc.o
fischillo: CMakeFiles/fischillo.dir/build.make
fischillo: CMakeFiles/fischillo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable fischillo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fischillo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fischillo.dir/build: fischillo

.PHONY : CMakeFiles/fischillo.dir/build

CMakeFiles/fischillo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fischillo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fischillo.dir/clean

CMakeFiles/fischillo.dir/depend:
	cd /home/jr/Desktop/SmartLock/Codigo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jr/Desktop/SmartLock/Codigo /home/jr/Desktop/SmartLock/Codigo /home/jr/Desktop/SmartLock/Codigo/build /home/jr/Desktop/SmartLock/Codigo/build /home/jr/Desktop/SmartLock/Codigo/build/CMakeFiles/fischillo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fischillo.dir/depend

