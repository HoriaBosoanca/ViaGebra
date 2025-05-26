cmake_minimum_required(VERSION 3.22)
project(ViaGebra)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(main ${SOURCES} include/main.h)
target_include_directories(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib-windows/raylib/include
)
target_link_libraries(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib-windows/raylib/lib/libraylib.a
        winmm
)