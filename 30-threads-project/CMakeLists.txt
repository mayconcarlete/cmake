cmake_minimum_required(VERSION 3.22.0)

set(CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(main LANGUAGES CXX)

find_package(Boost REQUIRED COMPONENTS thread system)

add_executable(
    main
    main.cpp
)

target_link_libraries(
    main
    PRIVATE
    Boost::thread
    Boost::system
)


