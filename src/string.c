#include <simpcl/string.h>

struct scl_string {
    struct scl_vector *data;
};

// life cycle
struct scl_string *scl_new_string() {
    struct scl_string *string = (struct scl_string *)malloc(sizeof(struct scl_string));

    if (!string) {
        return NULL;
    }

    string->data = scl_new_vector(sizeof(char));

    if (!string->data) {
        free(string);
        return NULL;
    }

    return string;
}

void scl_destroy_string(struct scl_string *string) {
    if (!string) return;
    scl_destroy_vector(string->data);
    free(string);
}

// edit functions
void scl_string_clear(struct scl_string *string) {
    scl_vector_clear(string->data);
}

void scl_string_append_cstring(struct scl_string *string, const char *c_string) {
    size_t cstring_size = strlen(c_string);

    for (size_t i = 0; i < cstring_size; i++) {
        scl_vector_push(string->data, &c_string[i]);
    }
}

// I/O
void scl_string_print(struct scl_string *string) {
    char terminator = '\0';
    scl_vector_push(string->data, &terminator);

    char *v_data = scl_vector_at(string->data, 0);
    fputs(v_data, stdout);
    scl_vector_pop(string->data, NULL);
}

void scl_string_readline(struct scl_string *string) {
    char c;

    while ((c = getchar()) != '\n' && c != EOF) {
        scl_vector_push(string->data, &c);
    }
}