# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Fundamentos de Ingeniería del Software
#
# @author José Ramón Morera Campos
# @date Apr 12 2023
# @brief CMakeLists.txt for the SmartLock project
# @see https://stackoverflow.com/questions/17525153/how-exactly-does-cmake-work
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(SmartLockApp              # Mandatory
    VERSION 0.9
    DESCRIPTION "Smartlock App"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17) 						# Use c++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -pedantic -O0")     #-o0 means disable optimizations (faster compilation)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")                      #-o3 means max optimization level (more compile time)

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "runTests" to be built from the source files listed in the command invocation.
# Add a new line for each new test file
add_executable(runTests
    test/gtest_main.cc
    test/test_smart_lock.cc)

# Adds an executable target called "SmartLockApp" to be built from the source files listed in the command invocation.
# Add a new line for each new .cc file

# Añadir archivos de código (.cc) aquí:
add_executable(SmartLockApp
    src/smart_lock_app.cc)

    
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Add expected compiler features to a target.
target_compile_features(runTests PRIVATE cxx_std_17)

# Add compile options to a target.
target_compile_options(runTests PRIVATE -Wall -Wextra -Wpedantic -Weffc++)
target_compile_options(SmartLockApp PRIVATE -Wall -Wextra -Wpedantic -Weffc++)

set(CMAKE_SKIP_INSTALL_RULES True) # Avoids creating install data