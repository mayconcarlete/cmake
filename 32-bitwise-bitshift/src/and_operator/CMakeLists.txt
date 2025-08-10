add_library(And_Comparison SHARED and_operator.c)
# Específica onde estão os .h (mesma pasta nesse exemplo).
target_include_directories(And_Comparison PUBLIC "./")