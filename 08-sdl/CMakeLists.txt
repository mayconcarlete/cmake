cmake_minimum_required(VERSION 3.22)

PROJECT(SDL_TEST VERSION 1.0.0 LANGUAGES C CXX)

if(WIN32)
    message("Compiling using WIN32")
    include_directories("./libs/sdl-win/include")
endif(WIN32)

if(LINUX)
    message("Compiling using WIN32")
    include_directories("./libs/sdl-linux/x86_64-w64-mingw32/include/SDL2")
endif(LINUX)

find_package(SDL2 REQUIRED)

add_executable(SDL_TEST "Main.cpp")

target_link_libraries(SDL_TEST 
SDL2::SDL2main
SDL2::SDL2
)
