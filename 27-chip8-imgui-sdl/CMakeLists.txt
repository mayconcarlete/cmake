cmake_minimum_required(VERSION 3.30.0)

project(main LANGUAGES CXX)


include_directories("./include")
file(GLOB Source "./src/*.cpp")


find_package(SDL2 REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(main main.cpp ${Source})

target_link_libraries(main
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)
target_link_libraries(main PRIVATE imgui::imgui)

# sudo apt-get install curl zip unzip tar pkg-config build-essential autoconf automake libtool pkg-config