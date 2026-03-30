#include <simpcl/vector.h>
#include <string.h>
#include <stdlib.h>

struct scl_vector {
    void *data;
    size_t size;
    size_t capacity;
    size_t type_size;
};

struct scl_vector *scl_new_vector(size_t type_size) {
    struct scl_vector *vector = (struct scl_vector *)malloc(sizeof(struct scl_vector));

    vector->size = 0;
    vector->capacity = 16;
    vector->type_size = type_size;

    vector->data = (void *)malloc(vector->type_size * vector->capacity);

    return vector;
}

void scl_destroy_vector(struct scl_vector *vector) {
    free(vector->data);
    free(vector);
}

size_t scl_vector_size(const struct scl_vector *vector) {
    return vector->size;
}

void *scl_vector_at(struct scl_vector *vector, size_t index) {
    if (index >= vector->size) return NULL;

    return (char *)vector->data + (index * vector->type_size);
}

void scl_vector_push(struct scl_vector *vector, void *element) {
    if (vector->size == vector->capacity) {
        size_t new_capacity = vector->capacity * 2;
        void *new_data = realloc(vector->data, new_capacity * vector->type_size);

        if (new_data) {
            vector->data = new_data;
            vector->capacity = new_capacity;
        }
    }

    void *target = (char *)vector->data + (vector->size * vector->type_size);

    memcpy(target, element, vector->type_size);

    vector->size++;
}

void scl_vector_reserve(struct scl_vector *vector, size_t reserve) {
    if (vector->capacity >= reserve) return;

    void *new_data = realloc(vector->data, vector->type_size * reserve);

    if (new_data) {
        vector->capacity = reserve;
        vector->data = new_data;
    }
}

void scl_vector_concat(struct scl_vector *vector, struct scl_vector *other) {
    scl_vector_reserve(vector, (vector->size + other->size));

    size_t other_size = other->size; // self concat protection
    
    for (size_t i = 0; i < other_size; i++) {
        scl_vector_push(vector, scl_vector_at(other, i));
    }
}

int scl_vector_is_empty(struct scl_vector *vector) {
    return !vector->size;
}

void scl_vector_pop(struct scl_vector *vector, void *out_dest) {
    if (vector->size == 0) return NULL;

    scl_vector_copy_element(vector, vector->size - 1, out_dest);
    vector->size--;
}

void scl_vector_clear(struct scl_vector *vector) {
    vector->size = 0;
}

void scl_vector_copy_element(struct scl_vector *vector, size_t index, void *out_dest) {
    if (index >= vector->size) return NULL;

    void *element_target = scl_vector_at(vector, index);

    memcpy(out_dest, element_target, vector->type_size);
}

void scl_vector_remove_at(struct scl_vector *vector, size_t index, void *out_dest) {
    if (index >= vector->size) return NULL;

    scl_vector_copy_element(vector, index, out_dest);

    void *target = (char *)vector->data + (vector->type_size * index);
    void *copy_target = (char *)vector->data + (vector->type_size * (index + 1));

    memmove(target, copy_target, vector->type_size * ((vector->size - 1) - index));

    vector->size--;
}

void scl_vector_shrink(struct scl_vector *vector) {
    size_t new_capacity = (vector->size < 16) ? 16 : vector->size;
    void *new_data = realloc(vector->data, vector->type_size * new_capacity);

    if (new_data) {
        vector->capacity = new_capacity;
        vector->data = new_data;
    }
}
