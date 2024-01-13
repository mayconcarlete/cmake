add_executable(${EXECUTABLE_NAME} main.c)


# Linkamos nossa library com o executavel main.c
target_link_libraries(${EXECUTABLE_NAME}  PUBLIC MyLibrary)
