cmake_minimum_required(VERSION 3.5...3.16)
project(unbounded_integer CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(unbounded_integer INTERFACE)

target_link_libraries(unbounded_integer INTERFACE src)