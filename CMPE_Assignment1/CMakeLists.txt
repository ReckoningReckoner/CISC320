cmake_minimum_required(VERSION 3.6)
project(CMPE_Assignment1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES TestInsultGenerator.cpp insultgenerator_14vb16.cpp insultgenerator_14vb16.h)
add_executable(CMPE_Assignment1 ${SOURCE_FILES})