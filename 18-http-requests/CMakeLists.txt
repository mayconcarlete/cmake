cmake_minimum_required(VERSION 3.22.0)

project(http-requests)

# set(CURL_LIBRARY "/home/maycon/dev/cpp/vcpkg/installed/x64-linux/lib/libcurl.a")
set(CURL_LIBRARY "./build")

# set(CURL_INCLUDE_DIR "/home/maycon/dev/cpp/vcpkg/installed/x64-linux/include/")
# set(CMAKE_BUILD_TYPE "Release")
find_package(CURL REQUIRED)

# include_directories("/home/maycon/dev/cpp/vcpkg/installed/x64-linux/include/")

add_executable(http-requests main.cpp)

target_link_libraries(http-requests PRIVATE CURL::libcurl)


# cmake -Bbuild -S. -DCMAKE_TOOLCHAIN_FILE="/home/maycon/dev/cpp/vcpkg/scripts/buildsystems/vcpkg.cmake"