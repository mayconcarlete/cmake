cmake_minimum_required(VERSION 3.22)

project(
    main
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CXX_STANDARD ${CXX_STANDARD})
set(IS_TEST ${IS_TEST})

include_directories(./src)

# add_executable(
#     main
#     ./src/main.cpp
#     ./src/math.cpp
# )

if(IS_TEST)
enable_testing()
add_test(main main)
add_executable(
    main
    ./src/math.cpp
    ./test/test_unit.cpp
    ./test/test_math.cpp
)
target_link_libraries(main ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
endif()


