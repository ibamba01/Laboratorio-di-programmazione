cmake_minimum_required(VERSION 3.24)
project(Laboratorio_Programmazione)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Laboratorio_Programmazione main.cpp timer.cpp timer.h)

target_link_libraries(Laboratorio_Programmazione ${CURSES_LIBRARIES})
