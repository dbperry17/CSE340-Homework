cmake_minimum_required(VERSION 3.6)
project(Homework)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES homework3.cpp inputbuf.h lexer.h inputbuf.cc lexer.cc)
add_executable(Homework ${SOURCE_FILES})