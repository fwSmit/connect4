cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
project (connect4)

#set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set (CMAKE_CXX_STANDARD 11)
add_executable(connect4 main.cpp Game.cpp Pieces.cpp Bot.cpp)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(connect4 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
