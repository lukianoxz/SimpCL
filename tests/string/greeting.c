#include <simpcl/string.h>

int main() {
    struct scl_string *s = scl_new_string();

    scl_string_append_cstring(s, "Hello, ");
    printf("Type your name: ");

    scl_string_readline(s);
    scl_string_append_cstring(s, "! Nice to meet you.\n");
    scl_string_print(s);

    scl_destroy_string(s);

    return 0;
}