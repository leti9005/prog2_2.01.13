cmake_minimum_required(VERSION 3.15)
project(sem2lab1)

set(CMAKE_CXX_STANDARD 14)

file(GLOB files "*.cpp" "*.h")

add_executable(sem2lab1 main.cpp)