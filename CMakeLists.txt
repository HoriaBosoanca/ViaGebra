cmake_minimum_required(VERSION 3.22)
project(ViaGebra)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(main ${SOURCES}
        include/main.h)
target_include_directories(main PRIVATE include)