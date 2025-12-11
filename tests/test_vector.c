#include <dsalib/vector/vector.h>
#include <assert.h>
#include <stdio.h>

void test_vector_basic() {
    printf("Testing vector...\n");

    dsalib_vector_t* vec = dsalib_vector_create(sizeof(int), 0);
    assert(vec != NULL);

    int a = 10, b = 20, c = 30;

    assert(dsalib_vector_push_back(vec, &a));
    assert(dsalib_vector_push_back(vec, &b));
    assert(dsalib_vector_push_back(vec, &c));

    int out;
    dsalib_vector_get(vec, 0, &out);
    assert(out == 10);

    dsalib_vector_get(vec, 2, &out);
    assert(out == 30);

    assert(dsalib_vector_size(vec) == 3);

    dsalib_vector_destroy(vec);
    printf("Vector tests passed!\n");
}

int main() {
    test_vector_basic();
    return 0;
}
