cmake_minimum_required(VERSION 3.22)

project (
    ConditionalPrint
    VERSION 1.0.0
    LANGUAGES C
)

if(WIN32)
    message("Compiling using WIN32")
    add_library(WinLibrary STATIC ./win/printa.c)
else()
    message("Compiling using Linux")
    add_library(LinuxLibrary STATIC ./linux/printa.c)
endif(WIN32)
    
add_executable(Main main.c)

if(WIN32)
    target_include_directories(WinLibrary PUBLIC "./include")
    target_link_libraries(Main PUBLIC WinLibrary)

else()
    target_include_directories(LinuxLibrary PUBLIC "./include")
    target_link_libraries(Main PUBLIC LinuxLibrary)

endif(WIN32)

