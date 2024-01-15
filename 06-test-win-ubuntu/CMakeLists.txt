cmake_minimum_required(VERSION 3.22)

project (
    ConditionalPrint
    VERSION 1.0.0
    LANGUAGES C
)

add_library(WinLibrary STATIC ./win/printa.c)

add_executable(Main main.c)

target_include_directories(WinLibrary PUBLIC "./include")

target_link_libraries(Main PUBLIC WinLibrary)
