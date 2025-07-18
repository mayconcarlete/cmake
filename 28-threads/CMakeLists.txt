CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# serve para desabilitar as extensões específicas do compilador (como -std=gnu++20) e forçar o uso do modo estritamente padrão (como -std=c++20) ao compilar C++.
set(CMAKE_CXX_EXTENSIONS OFF)

project(main
        VERSION 1.0.0
        LANGUAGES CXX
)

add_executable(
    main
    main.cpp
)