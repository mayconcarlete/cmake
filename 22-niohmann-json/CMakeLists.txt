cmake_minimum_required(VERSION 3.20.0)

project(Main LANGUAGES CXX)

find_package(nlohmann_json 3.11.3 REQUIRED)


add_executable(main main.cpp)

target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)