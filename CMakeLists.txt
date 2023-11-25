cmake_minimum_required(VERSION 3.14)

project(Cobalt VERSION 0.1.0)
message(STATUS "[Project] ${PROJECT_NAME}")

# Compile options
# set(CMAKE_C_COMPILER "clang")
# set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "-fno-asm -std=c++17 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(COBALT_BASE_DIR ${PROJECT_SOURCE_DIR})
message(STATUS "[Project] ${COBALT_BASE_DIR}")

set(COBALT_INCLUDE_DIR ${COBALT_BASE_DIR}/include)

# include_directories(include/cobalt/Frontend/Lexer/ include/cobalt/Frontend/Parser/)
include_directories(${COBALT_INCLUDE_DIR})
add_subdirectory(src/)