add_subdirectory(and_operator)

add_executable(
    main
    main.c
)

target_link_libraries(
    main
    PUBLIC
    And_Comparison    
)