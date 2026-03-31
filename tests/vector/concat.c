#include <simpcl/vector.h>
#include <simpcl/utils.h>

int main() {
    struct scl_vector *v = scl_new_vector(sizeof(int));
    struct scl_vector *v2 = scl_new_vector(sizeof(int));

    for (int i = 0; i <= 10; i++) {
        scl_vector_push(v, &i);
    }

    for (int i = 21; i <= 31; i++) {
        scl_vector_push(v2, &i);
    }

    scl_vector_concat(v, v2);

    scl_utils_print_int_vector(v);

    scl_destroy_vector(v);
    scl_destroy_vector(v2);

    return 0;
}