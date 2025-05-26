cmake_minimum_required(VERSION 3.22)
project(ViaGebra)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES CONFIGURE_DEPENDS
        src/*.cpp
        lib-windows/imgui/*.cpp
        lib-windows/rlimgui/*.cpp
)
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib-windows/raylib/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib-windows/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/lib-windows/rlimgui
)
target_link_libraries(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib-windows/raylib/lib/libraylib.a
        winmm
)