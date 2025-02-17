cmake_minimum_required(VERSION 3.0.0)


project(main LANGUAGES CXX)

include_directories(include)

find_package(cpr CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE cpr::cpr)