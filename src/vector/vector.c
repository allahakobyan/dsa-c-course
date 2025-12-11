#include "dsalib/vector/vector.h"
#include <stdlib.h>
#include <string.h>

dsalib_vector_t* dsalib_vector_create(size_t element_size, size_t initial_capacity) {
    if (element_size == 0) return NULL;

    if (initial_capacity == 0)
        initial_capacity = 4;

    dsalib_vector_t* vec = malloc(sizeof(dsalib_vector_t));
    if (!vec) return NULL;

    vec->data = malloc(element_size * initial_capacity);
    if (!vec->data) {
        free(vec);
        return NULL;
    }

    vec->element_size = element_size;
    vec->size = 0;
    vec->capacity = initial_capacity;

    return vec;
}

void dsalib_vector_destroy(dsalib_vector_t* vec) {
    if (!vec) return;
    free(vec->data);
    free(vec);
}

bool dsalib_vector_push_back(dsalib_vector_t* vec, const void* element) {
    if (!vec || !element) return false;

    if (vec->size == vec->capacity) {
        size_t new_capacity = vec->capacity * 2;
        void* new_data = realloc(vec->data, new_capacity * vec->element_size);
        if (!new_data) return false;
        vec->data = new_data;
        vec->capacity = new_capacity;
    }

    memcpy((char*)vec->data + vec->size * vec->element_size,
           element,
           vec->element_size);

    vec->size++;
    return true;
}

bool dsalib_vector_get(const dsalib_vector_t* vec, size_t index, void* out_value) {
    if (!vec || !out_value || index >= vec->size) return false;

    memcpy(out_value,
           (char*)vec->data + index * vec->element_size,
           vec->element_size);
    return true;
}

bool dsalib_vector_set(dsalib_vector_t* vec, size_t index, const void* element) {
    if (!vec || !element || index >= vec->size) return false;

    memcpy((char*)vec->data + index * vec->element_size,
           element,
           vec->element_size);
    return true;
}

bool dsalib_vector_is_empty(const dsalib_vector_t* vec) {
    return (!vec || vec->size == 0);
}

size_t dsalib_vector_size(const dsalib_vector_t* vec) {
    return vec ? vec->size : 0;
}

size_t dsalib_vector_capacity(const dsalib_vector_t* vec) {
    return vec ? vec->capacity : 0;
}

void dsalib_vector_clear(dsalib_vector_t* vec) {
    if (!vec) return;
    vec->size = 0;
}
