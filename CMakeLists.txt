cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE include)
target_link_libraries(main PRIVATE ${CMAKE_SOURCE_DIR}/lib/libraylib.a)