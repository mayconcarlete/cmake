cmake_minimum_required(VERSION 3.22.0)

project(
    main
    LANGUAGES
    CXX
)
set(CXX_STANDARD c++17)
find_package(Boost COMPONENTS system filesystem REQUIRED)
add_executable(
    main
    Main.cpp
)

target_link_libraries(main ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})