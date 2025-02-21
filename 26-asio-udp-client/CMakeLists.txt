cmake_minimum_required(VERSION 3.30.0)


project(main LANGUAGES CXX)

find_package(asio CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC asio::asio)