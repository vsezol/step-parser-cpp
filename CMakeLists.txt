cmake_minimum_required(VERSION 3.17)
project(step_parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(step_parser main.cpp StringUtils.cpp StringUtils.h FileReader.cpp FileReader.h VectorUtils.cpp VectorUtils.h)