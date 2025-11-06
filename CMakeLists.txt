cmake_minimum_required(VERSION 3.10)
project(ZeroMLC CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zero-mlc src/main.cpp)

target_compile_options(zero-mlc PRIVATE -fno-rtti)

target_include_directories(zero-mlc PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
