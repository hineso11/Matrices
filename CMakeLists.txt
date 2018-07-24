cmake_minimum_required(VERSION 3.10)
project(Matrices)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrices main.cpp matrix.cpp matrix.h row.cpp row.h)