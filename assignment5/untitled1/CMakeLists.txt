cmake_minimum_required(VERSION 3.20)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 Grammar.cpp Grammar.h Rule.cpp Rule.h grammar_tester.cpp)
