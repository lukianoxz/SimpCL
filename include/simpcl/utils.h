#ifndef SCL_UTILS_H
#define SCL_UTILS_H

#include <stdio.h>
#include <simpcl/vector.h>

static void scl_utils_print_int_vector(struct scl_vector *vector) {
    for (size_t i = 0; i < scl_vector_size(vector); i++) {
        printf("%d", *(int *)scl_vector_at(vector, i));
        
        if (i < (int)scl_vector_size(vector) - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

#endif