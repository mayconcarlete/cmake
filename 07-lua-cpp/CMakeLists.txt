cmake_minimum_required(VERSION 3.22)

PROJECT(hello VERSION 1.0.0 LANGUAGES C CXX)

file(GLOB lua_glob "./libs/lua/*.c")

include_directories("./libs/lua")
include_directories("./include")

add_executable(hello ${lua_glob} "./app/Main.cpp")