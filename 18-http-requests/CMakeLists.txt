cmake_minimum_required(VERSION 3.22.0)

project(http-requests)
# include("/home/maycon/dev/cpp/vcpkg/scripts/toolchains/android.cmake")

# set(ANDROID_NDK_HOME "/opt/android-ndk/build")

# set(CURL_LIBRARY "/home/maycon/dev/cd buicpp/vcpkg/installed/x64-linux/lib/libcurl.a")
set(CURL_LIBRARY "./build")
set(CURL_INCLUDE_DIR "./build")
# set(CMAKE_TOOLCHAIN_FILE "/home/maycon/dev/cpp/vcpkg/scripts/buildsystems/vcpkg.cmake")
# set(CURL_INCLUDE_DIR "/home/maycon/dev/cpp/vcpkg/installed/x64-linux/include/")
# set(CMAKE_BUILD_TYPE "Release")
find_package(CURL REQUIRED)

# include_directories("/home/maycon/dev/cpp/vcpkg/installed/x64-linux/include/")

add_executable(http-requests main.cpp)

target_link_libraries(http-requests PRIVATE CURL::libcurl)


# SÓ FUNCIONA POR LINHA DE COMANDO, NAO ADIANTA COLOCAR O MAKE_TOOLCHAIN_FILE COMO SET
# cmake -Bbuild -S. -DCMAKE_TOOLCHAIN_FILE="/home/maycon/dev/cpp/vcpkg/scripts/buildsystems/vcpkg.cmake"


# export ANDROID_NDK_HOME=/opt/android-ndk/build



# ./vcpkg install curl:arm-android  curl:arm64-android  curl:x64-android  curl:x86-android