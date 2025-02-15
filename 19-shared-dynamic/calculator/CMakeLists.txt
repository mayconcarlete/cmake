add_library(
    calculator
    STATIC
    ./src/calculator.cpp
)

target_include_directories(
    calculator
    PUBLIC
    ./include
)