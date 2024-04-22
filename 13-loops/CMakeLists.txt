cmake_minimum_required(VERSION 3.22.0)

set(VAR a)

#######################
# Loop
# Enquanto a variavel VAR nao for igual a "aaaaaaaaaa" print message
#######################
while(NOT VAR STREQUAL "aaaaaaaaaa")
    set(VAR ${VAR}a)
    message(${VAR})
endwhile()


# foreach(Name Alice;Bob;Charlie) tambem funciona
foreach(Name Alice Bob Charlie)
    message(${Name})
endforeach()

# using range
foreach(x RANGE 100 105)
    message("Person: ${x}")
endforeach()

# using range to walkthrough a list
set(MyList Maycon;Carolina;Iara)
foreach(x IN LISTS MyList)
    message("Person: ${x}")    
endforeach()
