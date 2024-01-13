cmake_minimum_required(VERSION 3.22)

project(
    LibrarySupport
    VERSION 1.0.0
    LANGUAGES C    
)

# definir primeiro a library e por ultimo o subdirectory do arquivo principal
# lembrar que sempre precisamos adicinoar um CMakeLists.txt para cada level que formos
# nesse caso estamos adicionando src / my_lib, portanto devemos adicionar
# um CmakeLists para cada folder e especificar que e um subdiretory
add_subdirectory(src) 
add_subdirectory(app)

