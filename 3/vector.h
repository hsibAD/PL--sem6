#include <stdio.h>
#include <inttypes.h>
#include <malloc.h>

struct vector;

struct vector* vector(size_t);
// int64_t get_index(size_t);
void add(struct vector*, int64_t);
void add_index(struct vector*, size_t, int64_t);
size_t get_capacity(struct vector*);
void set_capacity(struct vector*, size_t);
size_t get_length(struct vector*);
void print_vector(FILE*, struct vector*);
