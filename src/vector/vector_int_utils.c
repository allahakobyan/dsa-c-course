#include "dsalib/vector/vector_int_utils.h"
#include <stdio.h>   // fopen, fscanf, fclose

double dsalib_vector_int_mean(dsalib_vector_t *vec) {
    if (!vec || vec->size == 0) return 0.0;

    long sum = 0;
    for (size_t i = 0; i < vec->size; i++) {
        int value;
        dsalib_vector_get(vec, i, &value);
        sum += value;
    }
    return (double)sum / vec->size;
}

int dsalib_vector_int_min(dsalib_vector_t *vec) {
    if (!vec || vec->size == 0) return 0;

    int value, min;
    dsalib_vector_get(vec, 0, &min);

    for (size_t i = 1; i < vec->size; i++) {
        dsalib_vector_get(vec, i, &value);
        if (value < min) min = value;
    }
    return min;
}

int dsalib_vector_int_max(dsalib_vector_t *vec) {
    if (!vec || vec->size == 0) return 0;

    int value, max;
    dsalib_vector_get(vec, 0, &max);

    for (size_t i = 1; i < vec->size; i++) {
        dsalib_vector_get(vec, i, &value);
        if (value > max) max = value;
    }
    return max;
}

// simple O(n^2) sort, fine for this project
void dsalib_vector_int_sort(dsalib_vector_t *vec) {
    if (!vec) return;

    for (size_t i = 0; i < vec->size; i++) {
        for (size_t j = i + 1; j < vec->size; j++) {
            int a, b;
            dsalib_vector_get(vec, i, &a);
            dsalib_vector_get(vec, j, &b);
            if (a > b) {
                dsalib_vector_set(vec, i, &b);
                dsalib_vector_set(vec, j, &a);
            }
        }
    }
}

double dsalib_vector_int_median(dsalib_vector_t *vec) {
    if (!vec || vec->size == 0) return 0.0;

    // sort in-place
    dsalib_vector_int_sort(vec);

    if (vec->size % 2 == 1) {
        int mid;
        dsalib_vector_get(vec, vec->size / 2, &mid);
        return mid;
    } else {
        int a, b;
        dsalib_vector_get(vec, vec->size / 2 - 1, &a);
        dsalib_vector_get(vec, vec->size / 2, &b);
        return (a + b) / 2.0;
    }
}

int dsalib_vector_int_load_from_file(dsalib_vector_t *vec, const char *filename) {
    if (!vec || !filename) return -1;

    FILE *fp = fopen(filename, "r");
    if (!fp) return -1;

    int count = 0;
    int value;

    while (fscanf(fp, "%d", &value) == 1) {
        dsalib_vector_push_back(vec, &value);
        count++;
    }

    fclose(fp);
    return count;
}

