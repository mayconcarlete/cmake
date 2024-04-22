cmake_minimum_required(VERSION 3.22.0)

project(ExportedCalculator)


find_package(sum_lib)

if(sum_lib_FOUND)
    message("sum lib found")
    add_executable(calculator main.cpp)
    target_link_libraries(calculator Sum)
else()
    message(FATAL_ERROR "sum_lib library not found")
endif()
