cmake_minimum_required(VERSION 3.22.0)

function(print_detail name_var)
    message("My ${name_var} is ${${name_var}}")
endfunction()

set(Name Maycon)
set(Age 34)

print_detail(Name)
print_detail(Age)


# Function with default values
function(print name_var)
    if(DEFINED ARGV1)
        message("Hello my default name is: ${ARGV1}")
    else()
        message("Hello my name is: ${name_var}")
    endif()
endfunction()

set(Name2 Carolina)
print(${Name2})
print(Name Maykerops)

# function that prints all arg types
function(print_args Name)
    message("ARGVC: ${ARGC}")
    message("ARGV: ${ARGV}")
    message("ARGN: ${ARGN}")
endfunction()

print_args(${Name} Iara Carolina Alice)