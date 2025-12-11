# test_add
add_executable(test_add test_add.c)
target_link_libraries(test_add PRIVATE dsalib)
add_test(NAME test_add COMMAND test_add)

# test_linear_search
add_executable(test_linear_search test_linear_search.c)
target_link_libraries(test_linear_search PRIVATE dsalib)
add_test(NAME test_linear_search COMMAND test_linear_search)

# test_binary_search
add_executable(test_binary_search test_binary_search.c)
target_link_libraries(test_binary_search PRIVATE dsalib)
add_test(NAME test_binary_search COMMAND test_binary_search)

# test_stack
add_executable(test_stack test_stack.c)
target_link_libraries(test_stack PRIVATE dsalib)
add_test(NAME test_stack COMMAND test_stack)

# test_queue
add_executable(test_queue test_queue.c)
target_link_libraries(test_queue PRIVATE dsalib)
add_test(NAME test_queue COMMAND test_queue)

# test_vector
add_executable(test_vector test_vector.c)
target_link_libraries(test_vector PRIVATE dsalib)
add_test(NAME test_vector COMMAND test_vector)

# test_vector_int_utils
add_executable(test_vector_int_utils test_vector_int_utils.c)
target_link_libraries(test_vector_int_utils PRIVATE dsalib)
add_test(NAME test_vector_int_utils COMMAND test_vector_int_utils)