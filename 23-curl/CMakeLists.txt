cmake_minimum_required(VERSION 3.0.0)


project(main LANGUAGES CXX)

find_package(CURL REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE CURL::libcurl)