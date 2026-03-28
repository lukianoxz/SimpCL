#ifndef SCL_VECTOR_H
#define SCL_VECTOR_H

#include <stdlib.h> // for size_t

// opaque struct
struct scl_vector;

// vector functions
struct scl_vector* scl_new_vector(size_t type_size);
void               scl_vector_push(struct scl_vector* vector, void* element);
void*              scl_vector_get(struct scl_vector* vector, size_t index);
size_t             scl_vector_size(struct scl_vector* vector);
void               scl_vector_destroy(struct scl_vector* vector);

#endif