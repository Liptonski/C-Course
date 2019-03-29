cmake_minimum_required(VERSION 3.9)
project(projekt_BMP)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekt_BMP Rysownik.h bmp.h Interpreter.h main.cpp)