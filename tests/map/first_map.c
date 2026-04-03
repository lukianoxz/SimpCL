#include <simpcl/map.h>
#include <simpcl/string.h>
#include <simpcl/utils.h>

int map_int_callback(void *key, void *real_key) {
    return *(int *)key == *(int *)real_key;
}

void map_dest_callback(void *src) {
    free(src);
}

int main() {
    struct scl_map *m = scl_new_map(map_int_callback);

    for (size_t i = 0; i < 10; i++) {
        int *kp = (int *)malloc(sizeof(int));
        char *vp = (char *)malloc(sizeof(char));

        *kp = i;
        *vp = 'a' + i;

        scl_map_insert(m, kp, vp);
    }

    int k = 3;
    printf("%c\n", scl_map_get(m, &k));

    scl_utils_destroy_map_pointers(m, map_dest_callback, map_dest_callback);
    scl_destroy_map(m);

    return 0;
}