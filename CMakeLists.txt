cmake_minimum_required(VERSION 3.10)
project(SortMethods)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortMethods main.cpp Sort.h Sort.cpp Sort_Test.cpp quick_sort.h merge_sort.h shell_sort.h heap_sort.h)
