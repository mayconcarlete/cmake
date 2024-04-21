cmake_minimum_required(VERSION 3.22)

find_package(SDL2 REQUIRED)

PROJECT(SDL_TEST VERSION 1.0.0 LANGUAGES C CXX)

add_executable(main Main.cpp)