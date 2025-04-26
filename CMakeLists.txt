cmake_minimum_required(VERSION 3.30)
project(modern_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Wpedantic)

add_executable(auto_keyword auto_keyword.cpp)
add_executable(std_array std_array.cpp)
