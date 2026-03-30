A simple C library

## code example:

```c
#include <simpcl/vector.h>
#include <stdio.h>

int main(){
    struct scl_vector *v = scl_new_vector(sizeof(int));
    int n = 2;
    scl_vector_push(v, &n);

    printf("%d\n", *(int *)scl_vector_at(v, 0));

    scl_destroy_vector(v);

    return 0;
}
```