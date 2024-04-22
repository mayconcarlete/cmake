cmake_minimum_required(VERSION 3.22.0)

project(MyCalculator)

add_subdirectory(sum)
add_subdirectory(print)

add_executable(calculator
    main.cpp
)

target_link_libraries(calculator Sum Print)

