cmake_minimum_required(VERSION 3.13)
project(GameSimulator)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE sources *.cpp *.h)

add_executable(usageTest ${sources})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sequences.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})