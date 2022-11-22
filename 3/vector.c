#include "vector.h"

 

struct vector {
	int64_t* start_addr; 
	size_t capacity;
	size_t length;
};

struct vector* vector(size_t initCapacity) {
	struct vector* vect = malloc(sizeof(struct vector));
	vect->start_addr = malloc(sizeof(int64_t) * initCapacity);
	vect->capacity = initCapacity;
	vect->length = 0;
	return vect;
}

void add(struct vector* vect, int64_t value) {
	if (vect->capacity == vect->length) {
		vect->capacity = 2 * vect->capacity;
		vect->start_addr = realloc(vect->start_addr, vect->capacity * sizeof(int64_t));
	}
	vect->start_addr[vect->length++] = value;
}

void add_index(struct vector* vect, size_t index, int64_t value) {
	if (index > vect->capacity) { // maybe index + 1
		vect->capacity = 2 * index * sizeof(int64_t);
		vect->start_addr = realloc(vect->start_addr, vect->capacity);
	}
	vect->length = index + 1;
	vect->start_addr[index] = value; 
}

size_t get_capacity(struct vector* vect) {
	return vect->capacity;
}

void set_capacity(struct vector* vect, size_t _capacity) {
	vect->start_addr = realloc(vect->start_addr, _capacity * sizeof(int64_t));
	vect->capacity = _capacity;
}

size_t get_length(struct vector* vect) {
	return vect->length;
}

void print_vector(FILE* f, struct vector* vect) {
	fprintf(f, "\n [");
	for (int i = 0; i < vect->length; i++) {
		fprintf(f, "%" PRId64 " ", vect->start_addr[i]);
	}
	fprintf(f, "]");
}
