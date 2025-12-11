#ifndef DSALIB_VECTOR_INT_UTILS_H
#define DSALIB_VECTOR_INT_UTILS_H

#include <stddef.h>
#include "vector.h"

// All these functions assume the vector stores `int` elements
// (created with element_size = sizeof(int)).

// Statistics
double dsalib_vector_int_mean(dsalib_vector_t *vec);
double dsalib_vector_int_median(dsalib_vector_t *vec);
int    dsalib_vector_int_min(dsalib_vector_t *vec);
int    dsalib_vector_int_max(dsalib_vector_t *vec);

// Sorting (ascending)
void dsalib_vector_int_sort(dsalib_vector_t *vec);

// Load integers from a text file (numbers separated by spaces/newlines).
// Returns number of values loaded, or -1 on file error.
int dsalib_vector_int_load_from_file(dsalib_vector_t *vec, const char *filename);

#endif // DSALIB_VECTOR_INT_UTILS_H

