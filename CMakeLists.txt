cmake_minimum_required(VERSION 3.10)
project(ZeroMLC CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zero-mlc src/main.cpp)

target_include_directories(zero-mlc PUBLIC include)