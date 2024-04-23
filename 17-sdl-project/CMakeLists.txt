cmake_minimum_required(VERSION 3.22.0)

# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/Program Files (x86)/SDL2/")

project(sdl_project)

find_package(SDL2 REQUIRED)

add_executable(sdl_project Main.cpp)

target_link_libraries(sdl_project SDL2main SDL2)
# target_link_libraries(sdl_project SDL2::SDL2main SDL2::SDL2) 
