cmake_minimum_required(VERSION 3.22.0)

# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/Program Files (x86)/SDL2/")

project(sdl_project)


include(FetchContent)
set(SDL_VERSION 2.30.2)

# FetchContent_Declare(
#     sdl_lib
#     URL https://github.com/libsdl-org/SDL/archive/refs/tags/release-2.30.2.zip
#     FIND_PACKAGE_ARGS ${SDL_VERSION}
# )
# set(BUILD_EXAMPLES OFF CACHE INTERNAL "") para desativer build dos exemplos.

FetchContent_Declare(
    sdl_lib
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-2.30.2
)

FetchContent_MakeAvailable(sdl_lib)

# find_package(SDL2 REQUIRED)

add_executable(sdl_project Main.cpp)

target_link_libraries(sdl_project SDL2main SDL2)
# target_link_libraries(sdl_project SDL2::SDL2main SDL2::SDL2) 