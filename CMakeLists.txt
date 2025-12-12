cmake_minimum_required(VERSION 3.16)
project(my_project C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Create library
add_library(
    dsalib 
    src/containers/queue.c 
    src/containers/stack.c
    src/math/add.c 
    src/search/linear_search.c 
    src/search/binary_search.c
    src/vector/vector.c
    src/vector/vector_int_utils.c
)

target_include_directories(dsalib PUBLIC include)

add_executable(vector_demo demo/vector_demo.c)
target_link_libraries(vector_demo dsalib)

add_subdirectory(playground)

# Enable testing
enable_testing()
add_subdirectory(tests)
