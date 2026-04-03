#include <simpcl/map.h>

struct scl_map {
    struct scl_vector *map;
    int (*callback)(void *key, void *real_key);
};

struct scl_map_find_return {
    void *key, *value;
    size_t index;
};

// life cycle
struct scl_map *scl_new_map(int (*callback)(void *key, void *real_key)) {
    struct scl_map *map = (struct scl_map *)malloc(sizeof(struct scl_map));

    if (!map) return NULL;

    map->map = scl_new_vector(sizeof(struct scl_map_data));

    if (!map->map) {
        free(map);
        return NULL;
    }

    map->callback = callback;

    return map;
}

void scl_destroy_map(struct scl_map *map) {
    if (!map) return;
    scl_destroy_vector(map->map);
    free(map);
}

// access
struct scl_map_find_return scl_map_find(struct scl_map *map, void *key) {
    if (scl_vector_size(map->map) == 0) return (struct scl_map_find_return){NULL, NULL, 0};

    size_t map_size = scl_vector_size(map->map);
    struct scl_map_data *map_data = scl_vector_at(map->map, 0);

    for (size_t i = 0; i < map_size; i++) {
        struct scl_map_data data = map_data[i];

        if (map->callback(key, data.key)) {
            return (struct scl_map_find_return){data.key, data.value, i};
        }
    }

    return (struct scl_map_find_return){NULL, NULL, 0};
}

void *scl_map_get(struct scl_map *map, void *key) {
    struct scl_map_find_return res = scl_map_find(map, key);
    return (res.value) ? *(void **)res.value : NULL;
}

struct scl_vector *scl_map_data(struct scl_map *map) {
    return map->map;
}

// insertion
void scl_map_insert(struct scl_map *map, void *key, void *value) {
    struct scl_map_find_return res = scl_map_find(map, key);

    struct scl_map_data push = {key, value};

    if (!res.key) {
        scl_vector_push(map->map, &push);    
    } else {
        struct scl_map_data *data = scl_vector_at(map->map, res.index);
        data->value = value;
    }
}

// removal
struct scl_map_data scl_map_remove(struct scl_map *map, void *key) {
    struct scl_map_find_return res = scl_map_find(map, key);

    if (!res.value) return (struct scl_map_data){NULL, NULL};

    struct scl_map_data data = {res.key, res.value};

    scl_vector_remove_at(map->map, res.index, NULL);

    return data;
}