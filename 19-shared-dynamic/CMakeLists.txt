cmake_minimum_required(VERSION 3.22.0)

project(
    MyCalculator
    VERSION 1.0.0
    LANGUAGES C CXX
)


add_subdirectory(calculator)

add_executable(
    MyCalculator
    main.cpp
)

target_link_libraries(
    MyCalculator
    PUBLIC
    calculator
)