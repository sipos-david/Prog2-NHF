cmake_minimum_required(VERSION 3.13)
project(GameSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(usageTest test.cpp memtrace.cpp GameSimulator.cpp IOHandler.cpp MyString.cpp PlayerContainer.cpp SimulationLog.cpp SequencePlayer.cpp)