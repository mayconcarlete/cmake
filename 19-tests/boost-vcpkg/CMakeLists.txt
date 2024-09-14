cmake_minimum_required(VERSION 3.22.0)

project(
    main
    LANGUAGES
    CXX
)
set(CXX_STANDARD c++17)
set(CMAKE_CXX_COMPILER /usr/bin/c++)
find_package(Boost COMPONENTS system filesystem REQUIRED)
add_executable(
    main
    test_unit.cpp
    test_one.cpp
    test_two.cpp
)

target_link_libraries(main ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

enable_testing()
add_test(main main)
# sudo apt-get install autoconf automake autoconf-archive
# cmake -Bbuild -S. -DCMAKE_TOOLCHAIN_FILE="/home/maycon/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" -DVCPKG_TARGET_TRIPLET=x64-linux