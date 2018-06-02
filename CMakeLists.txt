cmake_minimum_required(VERSION 3.9)
project(rational)

set(CMAKE_CXX_STANDARD 11)

add_executable(rational rational.cpp)
#Uncomment to run the test cases in main

#add_library(rational rational.cpp rational.h)
#comment if you want to run main