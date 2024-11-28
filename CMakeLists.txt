cmake_minimum_required(VERSION 3.20)
project(
    vector_algebra
    VERSION 0.0.1
    DESCRIPTION "Pybind11 Test"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(libs/pybind11)

pybind11_add_module(vector_algebra vector_algebra.cpp)