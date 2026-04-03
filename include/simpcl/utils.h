#ifndef SCL_UTILS_H
#define SCL_UTILS_H

#include <stdio.h>
#include <simpcl/vector.h>
#include <simpcl/map.h>

static void scl_utils_print_int_vector(struct scl_vector *vector) {
    for (size_t i = 0; i < scl_vector_size(vector); i++) {
        printf("%d", *(int *)scl_vector_at(vector, i));
        
        if (i < (int)scl_vector_size(vector) - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

static void scl_utils_destroy_map_pointers(struct scl_map *map, void (*callback_key)(void *key), void (*callback_value)(void *key)) {
    size_t data_size = scl_vector_size(scl_map_data(map));
    struct scl_map_data *data = scl_vector_at(scl_map_data(map), 0);

    for (size_t i = 0; i < data_size; i++) {
        callback_key(data[i].key);
        callback_value(data[i].value);
    }
}

#endif