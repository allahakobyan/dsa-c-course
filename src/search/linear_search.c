#include "dsalib/search/linear_search.h"

int dsalib_linear_search(const int *arr, size_t size, int target) {
    if (arr == NULL || size == 0)
        return -1;

    for (size_t i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

