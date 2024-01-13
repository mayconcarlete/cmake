cmake_minimum_required(VERSION 3.16)



set(EXECUTABLE_NAME "PROJETAO")
set(My_Library "MyLibrary")


project(${EXECUTABLE_NAME} VERSION 1.0)

# option(COMPILE_EXECUTABLE "Wether to compile the executable." off)

add_subdirectory(src)
add_subdirectory(app)
# if(COMPILE_EXECUTABLE)
# else ()
#   message("W/o .exe")
# endif()

# we can set/change the variable on when make the project
# cmake --build . -DCOMPILE_EXECUTABLE on
# IMPORTANT -DNOME_DA_VARIAVEL SEM ESPAÇO