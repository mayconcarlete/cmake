add_library(Sum
src/sum.cpp
)

# target_include_directories(Sum PUBLIC include)
target_include_directories(Sum PUBLIC
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# pode-se adicionar mais de um arquivo aqui para ser enviado para o DESTINATION ex:
# install(FILES path1 path2 destination path_destination)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/sum_lib/sum.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/sum_lib)
# para instalar os targets
install(TARGETS Sum EXPORT my_export DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/sum_lib)

# instalar o pacote exportado my_export
install(EXPORT my_export FILE sum_lib-config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/sum_lib) 
# explicacao do codigo acima
# estamos instalando "export package" e renomeando atraves da diretiva FILE o nome do -config.cmake


# LEMBRAR DE RODAR O "MAKE INSTALL" COMO SUDO PARA INSTALAR NA PASTA /USR/LOCAL
# 1 - cmake -S . -B build
# 2 - make
# 3 - sudo make install