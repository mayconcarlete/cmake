cmake_minimum_required(VERSION 3.22.0)

project(Test2)

add_executable(
    Test2
    main.cpp
)

include_directories("${CMAKE_SOURCE_DIR}/libs/calculator/include")
find_library(Test_Lib calculator "${CMAKE_SOURCE_DIR}/libs/calculator/lib")


#  Para adicionar uma biblioteca .a ou .so 
# lembrar de trocar de static(.a) para shared no caso do .so na linha 19
include_directories("${CMAKE_SOURCE_DIR}/libs/jsoncpp/include")
add_library(
    jsoncpp
    STATIC
    IMPORTED
)
set_target_properties(
    jsoncpp
    PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libs/jsoncpp/lib/libjsoncpp.a"
)

target_link_libraries(
    Test2
    ${Test_Lib}
    jsoncpp
)