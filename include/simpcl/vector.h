#ifndef SCL_VECTOR_H
#define SCL_VECTOR_H

#include <stdlib.h> // for size_t

// opaque struct
struct scl_vector;

// life cycle
struct scl_vector* scl_new_vector(size_t type_size);
void               scl_vector_destroy(struct scl_vector* vector);

// information
size_t             scl_vector_size(struct scl_vector* vector);
int                scl_vector_is_empty(struct scl_vector* vector);

// insertion
void               scl_vector_push(struct scl_vector* vector, void* element);
void               scl_vector_concat(struct scl_vector* vector, struct scl_vector* other);

// removal
void*              scl_vector_pop(struct scl_vector* vector);
void*              scl_vector_remove_at(struct scl_vector* vector, size_t index);
void               scl_vector_clear(struct scl_vector* vector);

// access
void*              scl_vector_get(struct scl_vector* vector, size_t index);
void*              scl_vector_copy_element(struct scl_vector* vector, size_t index);

// memory
void               scl_vector_reserve(struct scl_vector* vector, size_t reserve);
void               scl_vector_shrink(struct scl_vector* vector);

#endif