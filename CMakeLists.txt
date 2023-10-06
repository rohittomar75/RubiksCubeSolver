cmake_minimum_required(VERSION 3.26)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCube main.cpp
        GenericRubiksCube.cpp
        GenericRubiksCube.h
        RubiksCube3D.cpp
        RubiksCubeBFS.cpp
        RubiksCubeBFS.h
)
