#include <simpcl/vector.h>
#include <stdio.h>

int main(){
    struct scl_vector* v = scl_new_vector(sizeof(int));
    int n = 2;
    scl_vector_push(v, &n);

    printf("%d\n", *(int*)scl_vector_get(v, 0));

    scl_vector_destroy(v);

    return 0;
}