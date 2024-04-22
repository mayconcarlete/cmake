cmake_minimum_required(VERSION 3.22.0)

project(MyCalculator)

add_subdirectory(sum)
add_subdirectory(print)

add_executable(calculator
    main.cpp
)

target_link_libraries(calculator Sum Print)


# e recomendado que se coloque os headers files e os targetsnas seguintes pastas:
# HEADER FILES -> user/local/include/<package-name>
# Targets -> user/local/lib/<package-name>
# message(${CMAKE_INSTALL_PREFIX})

# Nesse Exercicios copiaremos as libraries que criamos para os locais de instalacao
# CMakeLists modificado apenas os da libraries print e sum