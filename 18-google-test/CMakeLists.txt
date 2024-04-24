cmake_minimum_required(VERSION 3.22.0)

project(mygoogletest LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG release-1.11.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


include(GoogleTest)

add_executable(
    mygoogletest
    Main.cpp
)
target_link_libraries(mygoogletest gtest_main)
