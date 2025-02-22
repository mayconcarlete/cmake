cmake_minimum_required(VERSION 3.30.0)

project(main LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE fmt::fmt-header-only)
target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE OpenGL::GL)
target_link_libraries(main PRIVATE imgui::imgui)
target_link_libraries(main PRIVATE implot::implot)
target_link_libraries(main PRIVATE GLEW::GLEW)