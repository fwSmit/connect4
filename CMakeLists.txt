cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project (connect4)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set (CMAKE_CXX_STANDARD 11)
add_executable(connect4 main.cpp Game.cpp Pieces.cpp Bot.cpp)
