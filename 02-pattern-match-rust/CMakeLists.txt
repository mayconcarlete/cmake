# create code and Cmakefile
# create build folder (mkdir build)
# cd to build folder
# cmake ..  generate the Build Files / Configure the project
# cmake --build .
# ./Executable

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

add_executable(main main.cpp)