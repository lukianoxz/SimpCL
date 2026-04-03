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

// information
static inline char _scl_string_at(const struct scl_string *string, size_t index) {
    return *(char *)scl_vector_at(string->data, index);
}

static inline size_t _scl_string_size(const struct scl_string *string) {
    return scl_vector_size(string->data);
}

int scl_string_compare(const struct scl_string *string, const struct scl_string *other) {
    size_t string_size = _scl_string_size(string);
    size_t other_size = _scl_string_size(other);

    if (string_size != other_size) return 0;

    for (size_t i = 0; i < string_size; i++) {
        if (_scl_string_at(string, i) != _scl_string_at(other, i)) return 0;
    }

    return 1;
}

char *scl_string_to_cstring(const struct scl_string *string) {
    size_t string_size = _scl_string_size(string);
    char *cstring = (char *)malloc(sizeof(char) * (string_size + 1));

    if (!cstring) return NULL;

    void *string_data = scl_vector_at(string->data, 0);
    cstring[string_size] = '\0';
    memcpy(cstring, string_data, string_size);

    return cstring;
}

// edit functions
void scl_string_clear(struct scl_string *string) {
    scl_vector_clear(string->data);
}

void scl_string_append_cstring(struct scl_string *string, const char *c_string) {
    size_t cstring_size = strlen(c_string);
    char c;

    for (size_t i = 0; i < cstring_size; i++) {
        c = c_string[i];
        scl_vector_push(string->data, &c);
    }
}

// I/O
void scl_string_print(const struct scl_string *string) {
    size_t string_size = _scl_string_size(string);
    char *string_data = scl_vector_at(string->data, 0);

    for (size_t i = 0; i < string_size; i++) {
        putchar(string_data[i]);
    }
}

void scl_string_readline(struct scl_string *string) {
    int ic;

    while ((ic = getchar()) != '\n' && ic != EOF) {
        char c = (char)ic;
        scl_vector_push(string->data, &c);
    }
}