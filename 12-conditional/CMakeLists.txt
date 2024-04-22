cmake_minimum_required(VERSION 3.22.0)


# Variavel sera considerada "true" se o valor dela for: YES, TRUE, ON, 1, Y, a nom zero number
# Variavel sera considerada "false" se o valor da mesma for: 0, OFF, NO, FALSE, N, IGNORE, NOTFOUND, empty string, string ending with -NOTFOUND

# cmake -P CMakeLists.txt para rodar script

set(VAR YES)
######################################
# Checks if the variable is true/false
######################################
if(VAR)
    message("If block executed")
else()
    message("Else block executed")
endif()

set(Name Maycon)

###################################
# Checks if the variable is defined
###################################
if(DEFINED Name)
    message("Name: if block executed")
else()
    message("Name: else block executed")
endif()

if(DEFINED Age)
    message("Age: if block executed")
else()
    message("Age: else block executed")
endif()

########################################
# Checks if the value is a valid command
########################################
if(COMMAND target_link_libraries)
    message("target_link_libraries: IF block")
else()
    message("target_link_libraries: Else block")
endif()

if(COMMAND target_link_library)
    message("target_link_library: IF block")
else()
    message("target_link_library: Else block")
endif()

#######################
# Checks if file exists
#######################
if(EXISTS "/home/maycon/dev/cpp/cmake/12-conditional/CMakeLists.txt")
    message("File Exists iF block")
else()
    message("File doesn't exist Else block")
endif()

if(EXISTS "/home/maycon/dev/cpp/cmake/12-conditional/doesntexist.txt")
    message("File Exists iF block")
else()
    message("File doesn't exist Else block")
endif()

#######################
# Compare two strings
# Attention, STRLESS avalia o case sensitive, ou seja ALICE e menor que BOB pois o A vem primeiro. O que importa e a posicao alfabetica e nao o tamanho
#######################
set(Name1 alice)
set(Name2 bob)
if(Name1 STRLESS Name2)
    message("${Name1} is less than ${Name2}")
elseif(Name1 STRGREATER Name2)
    message("${Name1} is greater than ${Name2}")
elseif(Name1 STREQUAL Name2)
    message("${Name1} is equal ${Name2}")
endif()
