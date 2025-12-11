#include <dsalib/search/binary_search.h>
#include <assert.h>
#include <stdio.h>

// forward declare
void test_lower_bound();

void test_lower_bound() {
    printf("Testing lower_bound...\n");

    int arr1[] = {1, 3, 5, 7, 9, 11, 13};
    assert(dsalib_lower_bound(arr1, 7, 7) == 3);
    assert(dsalib_lower_bound(arr1, 7, 0) == 0);
    assert(dsalib_lower_bound(arr1, 7, 20) == 7);
    assert(dsalib_lower_bound(arr1, 7, 6) == 3);

    int empty[] = {};
    assert(dsalib_lower_bound(empty, 0, 5) == 0);
    assert(dsalib_lower_bound(NULL, 5, 5) == 0);

    int one[] = {42};
    assert(dsalib_lower_bound(one, 1, 42) == 0);
    assert(dsalib_lower_bound(one, 1, 10) == 0);
    assert(dsalib_lower_bound(one, 1, 50) == 1);

    int dup[] = {1, 3, 3, 3, 5};
    assert(dsalib_lower_bound(dup, 5, 3) == 1);

    printf("All lower_bound tests passed!\n\n");
}

void test_binary_search() {
    printf("Testing binary_search...\n");

    int arr1[] = {1, 3, 5, 7, 9, 11, 13};
    assert(dsalib_binary_search(arr1, 7, 7) == 3);
    assert(dsalib_binary_search(arr1, 7, 1) == 0);
    assert(dsalib_binary_search(arr1, 7, 13) == 6);
    assert(dsalib_binary_search(arr1, 7, 0) == -1);
    assert(dsalib_binary_search(arr1, 7, 20) == -1);
    assert(dsalib_binary_search(arr1, 7, 6) == -1);

    printf("All binary_search tests passed!\n\n");
}

void test_binary_search_recursive() {
    printf("Testing binary_search_recursive...\n");

    int arr1[] = {1, 3, 5, 7, 9, 11, 13};
    assert(dsalib_binary_search_recursive(arr1, 0, 6, 7) == 3);
    assert(dsalib_binary_search_recursive(arr1, 0, 6, 1) == 0);
    assert(dsalib_binary_search_recursive(arr1, 0, 6, 13) == 6);

    printf("All recursive tests passed!\n\n");
}

int main() {
    printf("================================\n");
    printf("Search Algorithms Test Suite\n");
    printf("================================\n\n");

    test_lower_bound();
    test_binary_search();
    test_binary_search_recursive();

    printf("================================\n");
    printf("All tests passed successfully!\n");
    printf("================================\n");
    return 0;
}

