#include <simpcl/vector.h>
#include <simpcl/utils.h>

int main() {
    struct scl_vector *v = scl_new_vector(sizeof(int));

    for (int i = 0; i <= 10; i++) {
        scl_vector_push(v, &i);
    }

    scl_utils_print_int_vector(v);

    scl_destroy_vector(v);

    return 0;
}