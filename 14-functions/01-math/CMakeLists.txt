cmake_minimum_required(VERSION 3.22)

project(
    main
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CXX_STANDARD ${CXX_STANDARD})
set(MODE ${MODE})



include_directories(./src)
#################################################
# Build Unit Tests.
#################################################
if(${MODE} STREQUAL "UNIT_TEST")
file(GLOB TEST_SRC_FILES "./test/*.cpp")
enable_testing()
add_test(main main)
add_executable(
    main
    ./src/math.cpp
    ${TEST_SRC_FILES}
)
target_link_libraries(main ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
endif()
#################################################
# Build the code in Debug Mode.
#################################################
if(${MODE} STREQUAL "DEBUG")
add_executable(
    main
    ./src/main.cpp
    ./src/math.cpp
)
endif()
