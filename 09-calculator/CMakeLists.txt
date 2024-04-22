cmake_minimum_required(VERSION 3.22.0)

project(MyCalculator)

add_library(Sum
sum.cpp
)

add_library(Print
print.cpp
)

add_executable(calculator
    main.cpp
)
target_link_libraries(calculator Sum Print)

