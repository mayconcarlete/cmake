add_library(${My_Library} STATIC my_lib.c)

# especifica onde estao os aquivos .h including
# nesse caso mesmo nivel entao ./
target_include_directories(${My_Library} PUBLIC "./")