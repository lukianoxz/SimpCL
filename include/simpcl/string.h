#ifndef SCL_STRING_H
#define SCL_STRING_H

#include <simpcl/vector.h>
#include <stdio.h>
#include <string.h>

// opaque struct
struct scl_string;

// life cycle
struct scl_string *scl_new_string();
void               scl_destroy_string(struct scl_string *string);

// information
int                scl_string_compare(const struct scl_string *string, const struct scl_string *other);
char              *scl_string_to_cstring(const struct scl_string *string);

// edit functions
void               scl_string_clear(struct scl_string *string);
void               scl_string_append_cstring(struct scl_string *string, const char *c_string);

// I/O
void               scl_string_print(const struct scl_string *string);
void               scl_string_readline(struct scl_string *string);

#endif