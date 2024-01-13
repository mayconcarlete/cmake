cmake_minimum_required(VERSION 3.22)

project(
    LibrarySupport
    VERSION 1.0.0
    LANGUAGES C    
)

add_library(MyLibrary STATIC my_lib.c)

add_executable(LibSupport main.c)

# Linkamos nossa library com o executavel main.c
target_link_libraries(LibSupport  PUBLIC MyLibrary) 