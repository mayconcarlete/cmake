add_library(
    calculator
    SHARED
    ./src/calculator.cpp
)

target_include_directories(
    calculator
    PUBLIC
    ./include
)