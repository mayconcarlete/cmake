cmake_minimum_required(VERSION 3.22.0)

project(Test)

add_executable(
    Test
    main.cpp
)

include_directories("${CMAKE_SOURCE_DIR}/libs/calculator/include")
find_library(Test_Lib calculator "${CMAKE_SOURCE_DIR}/libs/calculator/lib")

target_link_libraries(
    Test
    ${Test_Lib}
)