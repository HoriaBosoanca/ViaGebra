cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE include)
if(UNIX)
    target_link_libraries(main PRIVATE ${CMAKE_SOURCE_DIR}/lib/libraylib.a)
elseif(WIN32)
    target_link_libraries(main PRIVATE ${CMAKE_SOURCE_DIR}/lib-windows/libraylib.a winmm)
endif()