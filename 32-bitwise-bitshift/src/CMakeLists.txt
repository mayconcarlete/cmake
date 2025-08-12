add_subdirectory(and_operator)
add_subdirectory(or_operator)

add_executable(
    main
    main.c
)

target_link_libraries(
    main
    PUBLIC
    and_operator
    or_operator
)