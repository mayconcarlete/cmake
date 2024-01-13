add_executable(LibSupport main.c)


# Linkamos nossa library com o executavel main.c
target_link_libraries(LibSupport  PUBLIC MyLibrary)
