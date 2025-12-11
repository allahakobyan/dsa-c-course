#include <dsalib/vector/vector.h>
#include <dsalib/vector/vector_int_utils.h>
#include <assert.h>
#include <stdio.h>

void test_basic_stats() {
    dsalib_vector_t *v = dsalib_vector_create(sizeof(int), 0);

    int a = 2, b = 4, c = 6, d = 8;
    dsalib_vector_push_back(v, &a);
    dsalib_vector_push_back(v, &b);
    dsalib_vector_push_back(v, &c);
    dsalib_vector_push_back(v, &d);

    // Values: 2,4,6,8 → mean = 5, min = 2, max = 8, median = (4+6)/2 = 5
    double mean = dsalib_vector_int_mean(v);
    assert(mean == 5.0);

    assert(dsalib_vector_int_min(v) == 2);
    assert(dsalib_vector_int_max(v) == 8);

    double median = dsalib_vector_int_median(v); // also sorts
    assert(median == 5.0);

    printf("✓ basic stats test passed\n");

    dsalib_vector_destroy(v);
}

void test_load_from_file() {
    // create a small temp file
    const char *filename = "vector_test_data.txt";
    FILE *f = fopen(filename, "w");
    assert(f != NULL);
    // 3 numbers: 10 20 30
    fprintf(f, "10 20 30\n");
    fclose(f);

    dsalib_vector_t *v = dsalib_vector_create(sizeof(int), 0);
    int loaded = dsalib_vector_int_load_from_file(v, filename);
    assert(loaded == 3);

    int x;
    dsalib_vector_get(v, 0, &x); assert(x == 10);
    dsalib_vector_get(v, 1, &x); assert(x == 20);
    dsalib_vector_get(v, 2, &x); assert(x == 30);

    printf("✓ load_from_file test passed\n");

    dsalib_vector_destroy(v);
}

int main(void) {
    printf("=== vector_int_utils tests ===\n");
    test_basic_stats();
    test_load_from_file();
    printf("All vector_int_utils tests passed!\n");
    return 0;
}
