add_library(and_operator SHARED and_operator.c)
# Específica onde estão os .h (mesma pasta nesse exemplo).
target_include_directories(and_operator PUBLIC "./")