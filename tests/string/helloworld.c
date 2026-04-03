#include <simpcl/string.h>

int main() {
    struct scl_string *string = scl_new_string();

    scl_string_append_cstring(string, "Hello, World!\n");
    scl_string_print(string);

    scl_destroy_string(string);
    
    return 0;
}