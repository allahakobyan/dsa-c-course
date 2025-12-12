#include <stdio.h>
#include "dsalib/vector/vector.h"
#include "dsalib/vector/vector_int_utils.h"

int main(void) {
    printf("=== C-Vector Demo Application ===\n\n");

    // 1. Create a vector for integers
    dsalib_vector_t *vec = dsalib_vector_create(sizeof(int), 0);
    if (!vec) {
        printf("Failed to create vector\n");
        return 1;
    }

    // 2. Insert elements
    int values[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        dsalib_vector_push_back(vec, &values[i]);
    }

    printf("Vector size: %zu\n", dsalib_vector_size(vec));
    printf("Vector capacity: %zu\n\n", dsalib_vector_capacity(vec));

    // 3. Access elements
    printf("Vector elements:\n");
    for (size_t i = 0; i < dsalib_vector_size(vec); i++) {
        int value;
        dsalib_vector_get(vec, i, &value);
        printf("  vec[%zu] = %d\n", i, value);
    }

    // 4. Statistics
    printf("\nStatistics:\n");
    printf("  Mean: %.2f\n", dsalib_vector_int_mean(vec));
    printf("  Median: %.2f\n", dsalib_vector_int_median(vec));
    printf("  Min: %d\n", dsalib_vector_int_min(vec));
    printf("  Max: %d\n", dsalib_vector_int_max(vec));

    // 5. Sorting
    dsalib_vector_int_sort(vec);
    printf("\nSorted vector:\n");
    for (size_t i = 0; i < dsalib_vector_size(vec); i++) {
        int value;
        dsalib_vector_get(vec, i, &value);
        printf("  %d\n", value);
    }

    // 6. Cleanup
    dsalib_vector_destroy(vec);
    printf("\nVector destroyed successfully.\n");

    return 0;
}
