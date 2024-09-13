cmake_minimum_required(VERSION 3.22.0)

project(
    main
    LANGUAGES
    CXX
)
set(CXX_STANDARD c++17)
#################################################
# Google Test
#################################################
enable_testing()
find_package(GTest CONFIG REQUIRED)

add_executable(
    main
    Main.cpp
)

target_link_libraries(main PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain main)
# cmake -S. -Bbuild -DCMAKE_TOOLCHAIN_FILE=C:\Users\mayco\dev\vcpkg\scripts\buildsystems\vcpkg.cmake