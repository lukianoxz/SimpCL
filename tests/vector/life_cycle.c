#include <simpcl/vector.h>
#include <stdio.h>

int main() {
    struct scl_vector *v = scl_new_vector(sizeof(int));

    scl_destroy_vector(v);

    return 0;
}