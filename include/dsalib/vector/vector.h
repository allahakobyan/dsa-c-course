#ifndef DSALIB_VECTOR_H
#define DSALIB_VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    void* data;
    size_t element_size;
    size_t size;
    size_t capacity;
} dsalib_vector_t;

/**
 * Creates a generic dynamic vector.
 *
 * @param element_size Size of each element in bytes
 * @param initial_capacity Initial capacity (0 uses default)
 * @return Pointer to vector or NULL if allocation fails
 */

dsalib_vector_t* dsalib_vector_create(size_t element_size, size_t initial_capacity);
void dsalib_vector_destroy(dsalib_vector_t* vec);

bool dsalib_vector_push_back(dsalib_vector_t* vec, const void* element);
bool dsalib_vector_get(const dsalib_vector_t* vec, size_t index, void* out_value);
bool dsalib_vector_set(dsalib_vector_t* vec, size_t index, const void* element);

bool dsalib_vector_is_empty(const dsalib_vector_t* vec);
size_t dsalib_vector_size(const dsalib_vector_t* vec);
size_t dsalib_vector_capacity(const dsalib_vector_t* vec);

void dsalib_vector_clear(dsalib_vector_t* vec);

#endif
