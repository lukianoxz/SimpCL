#include <simpcl/string.h>

struct scl_string {
    struct scl_vector *data;
};

struct scl_string *scl_new_string(){
    struct scl_string *string = (struct scl_string *)malloc(sizeof(struct scl_string));

    string->data = scl_new_vector(sizeof(char));

    return string;
}

void scl_destroy_string(struct scl_string *string){
    scl_destroy_vector(string->data);
    free(string);
}