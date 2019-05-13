cmake_minimum_required(VERSION 3.13)
project(GameSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(usageTest test.cpp GameSimulator.cpp IOHandler.cpp MyString.cpp PlayerContainer.cpp SimulationLog.cpp SequencePlayer.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sequences.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
