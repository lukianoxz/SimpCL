#ifndef SCL_MAP_H
#define SCL_MAP_H

#include <simpcl/vector.h>
#include <stdlib.h>

struct scl_map;

struct scl_map_data {
    void *key, *value
};

// life cycle
struct scl_map     *scl_new_map(int (*callback)(void *key, void *real_key));
void                scl_destroy_map(struct scl_map *map);

// access
/*
struct scl_map_find_return {
    void *key, *value;
    size_t index;
};
struct scl_map_find_return scl_map_find(struct scl_map *map, void *key); use if you need pointer to key/value
*/
void               *scl_map_get(struct scl_map *map, void *key);
struct scl_vector  *scl_map_data(struct scl_map *map);

// insertion
void                scl_map_insert(struct scl_map *map, void *key, void *value);

// removal
struct scl_map_data scl_map_remove(struct scl_map *map, void *key);

#endif