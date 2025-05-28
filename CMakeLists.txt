cmake_minimum_required(VERSION 3.22)
project(ViaGebra)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES CONFIGURE_DEPENDS
        src/*.cpp
        lib/imgui/*.cpp
        lib/rlimgui/*.cpp
)
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/rlimgui
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/lua/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/sol2
)
target_link_libraries(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib/lib/libraylib.a
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/lua/lib/lua54.lib
        winmm
)
add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/lib/lua/lib/lua54.dll"
        "$<TARGET_FILE_DIR:main>"
)