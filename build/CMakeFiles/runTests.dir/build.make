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
CMAKE_BINARY_DIR = /home/jr/Desktop/SmartLock/build

# Include any dependencies generated for this target.
include CMakeFiles/runTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTests.dir/flags.make

CMakeFiles/runTests.dir/test/gtest_main.cc.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/test/gtest_main.cc.o: /home/jr/Desktop/SmartLock/Codigo/test/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTests.dir/test/gtest_main.cc.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/test/gtest_main.cc.o -c /home/jr/Desktop/SmartLock/Codigo/test/gtest_main.cc

CMakeFiles/runTests.dir/test/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/test/gtest_main.cc.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/test/gtest_main.cc > CMakeFiles/runTests.dir/test/gtest_main.cc.i

CMakeFiles/runTests.dir/test/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/test/gtest_main.cc.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/test/gtest_main.cc -o CMakeFiles/runTests.dir/test/gtest_main.cc.s

CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.o: /home/jr/Desktop/SmartLock/Codigo/test/test_cerradura_inteligente.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.o -c /home/jr/Desktop/SmartLock/Codigo/test/test_cerradura_inteligente.cc

CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/test/test_cerradura_inteligente.cc > CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.i

CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/test/test_cerradura_inteligente.cc -o CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.s

CMakeFiles/runTests.dir/test/test_base_datos.cc.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/test/test_base_datos.cc.o: /home/jr/Desktop/SmartLock/Codigo/test/test_base_datos.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/runTests.dir/test/test_base_datos.cc.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/test/test_base_datos.cc.o -c /home/jr/Desktop/SmartLock/Codigo/test/test_base_datos.cc

CMakeFiles/runTests.dir/test/test_base_datos.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/test/test_base_datos.cc.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/test/test_base_datos.cc > CMakeFiles/runTests.dir/test/test_base_datos.cc.i

CMakeFiles/runTests.dir/test/test_base_datos.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/test/test_base_datos.cc.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/test/test_base_datos.cc -o CMakeFiles/runTests.dir/test/test_base_datos.cc.s

CMakeFiles/runTests.dir/test/test_usuarios.cc.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/test/test_usuarios.cc.o: /home/jr/Desktop/SmartLock/Codigo/test/test_usuarios.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/runTests.dir/test/test_usuarios.cc.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/test/test_usuarios.cc.o -c /home/jr/Desktop/SmartLock/Codigo/test/test_usuarios.cc

CMakeFiles/runTests.dir/test/test_usuarios.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/test/test_usuarios.cc.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/test/test_usuarios.cc > CMakeFiles/runTests.dir/test/test_usuarios.cc.i

CMakeFiles/runTests.dir/test/test_usuarios.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/test/test_usuarios.cc.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/test/test_usuarios.cc -o CMakeFiles/runTests.dir/test/test_usuarios.cc.s

CMakeFiles/runTests.dir/src/cliente_funciones.cc.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/src/cliente_funciones.cc.o: /home/jr/Desktop/SmartLock/Codigo/src/cliente_funciones.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/runTests.dir/src/cliente_funciones.cc.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/src/cliente_funciones.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/cliente_funciones.cc

CMakeFiles/runTests.dir/src/cliente_funciones.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/src/cliente_funciones.cc.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/cliente_funciones.cc > CMakeFiles/runTests.dir/src/cliente_funciones.cc.i

CMakeFiles/runTests.dir/src/cliente_funciones.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/src/cliente_funciones.cc.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/cliente_funciones.cc -o CMakeFiles/runTests.dir/src/cliente_funciones.cc.s

CMakeFiles/runTests.dir/src/base_datos.cc.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/src/base_datos.cc.o: /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/runTests.dir/src/base_datos.cc.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/src/base_datos.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc

CMakeFiles/runTests.dir/src/base_datos.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/src/base_datos.cc.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc > CMakeFiles/runTests.dir/src/base_datos.cc.i

CMakeFiles/runTests.dir/src/base_datos.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/src/base_datos.cc.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/base_datos.cc -o CMakeFiles/runTests.dir/src/base_datos.cc.s

CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.o: /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc

CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc > CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.i

CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/cerradura_inteligente.cc -o CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.s

CMakeFiles/runTests.dir/src/usuario.cc.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/src/usuario.cc.o: /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/runTests.dir/src/usuario.cc.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/src/usuario.cc.o -c /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc

CMakeFiles/runTests.dir/src/usuario.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/src/usuario.cc.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc > CMakeFiles/runTests.dir/src/usuario.cc.i

CMakeFiles/runTests.dir/src/usuario.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/src/usuario.cc.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jr/Desktop/SmartLock/Codigo/src/usuario.cc -o CMakeFiles/runTests.dir/src/usuario.cc.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/test/gtest_main.cc.o" \
"CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.o" \
"CMakeFiles/runTests.dir/test/test_base_datos.cc.o" \
"CMakeFiles/runTests.dir/test/test_usuarios.cc.o" \
"CMakeFiles/runTests.dir/src/cliente_funciones.cc.o" \
"CMakeFiles/runTests.dir/src/base_datos.cc.o" \
"CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.o" \
"CMakeFiles/runTests.dir/src/usuario.cc.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/test/gtest_main.cc.o
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/test/test_cerradura_inteligente.cc.o
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/test/test_base_datos.cc.o
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/test/test_usuarios.cc.o
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/src/cliente_funciones.cc.o
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/src/base_datos.cc.o
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/src/cerradura_inteligente.cc.o
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/src/usuario.cc.o
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/build.make
/home/jr/Desktop/SmartLock/Codigo/build/runTests: /usr/local/lib/libgtest.a
/home/jr/Desktop/SmartLock/Codigo/build/runTests: CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jr/Desktop/SmartLock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable /home/jr/Desktop/SmartLock/Codigo/build/runTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTests.dir/build: /home/jr/Desktop/SmartLock/Codigo/build/runTests

.PHONY : CMakeFiles/runTests.dir/build

CMakeFiles/runTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTests.dir/clean

CMakeFiles/runTests.dir/depend:
	cd /home/jr/Desktop/SmartLock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jr/Desktop/SmartLock/Codigo /home/jr/Desktop/SmartLock/Codigo /home/jr/Desktop/SmartLock/build /home/jr/Desktop/SmartLock/build /home/jr/Desktop/SmartLock/build/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runTests.dir/depend

