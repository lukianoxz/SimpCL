#include <simpcl/vector.h>
#include <string.h>
#include <stdlib.h>

struct scl_vector {
    void* data;
    size_t size;
    size_t capacity;
    size_t type_size;
};

struct scl_vector* scl_new_vector(size_t type_size) {
    struct scl_vector* vector = (struct scl_vector*)malloc(sizeof(struct scl_vector));

    vector->size = 0;
    vector->capacity = 16;
    vector->type_size = type_size;

    vector->data = (void*)malloc(vector->type_size * vector->capacity);

    return vector;
}

void scl_vector_push(struct scl_vector* vector, void* element) {
    if (vector->size == vector->capacity) {
        size_t new_capacity = vector->capacity * 2;
        void* new_data = realloc(vector->data, new_capacity * vector->type_size);

        if (new_data) {
            vector->data = new_data;
            vector->capacity = new_capacity;
        }
    }

    void* target = (char*)vector->data + (vector->size * vector->type_size);

    memcpy(target, element, vector->type_size);

    vector->size++;
}

void* scl_vector_get(struct scl_vector* vector, size_t index) {
    if (index >= vector->size) return NULL;

    return (char*)vector->data + (index * vector->type_size);
}

size_t scl_vector_size(struct scl_vector* vector) {
    return vector->size;
}

void scl_vector_destroy(struct scl_vector* vector) {
    free(vector->data);
    free(vector);
}