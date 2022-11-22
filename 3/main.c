#include <inttypes.h>
#include "vector.h"


int main() {
	struct vector* vect = vector(5);
	add(vect, 5);
	add(vect, 1);
	add(vect, 7);
	print_vector(stdout, vect);
	add(vect, 9);
	add(vect, 123);
	add(vect, 34);
	print_vector(stdout, vect);
	return 0;
}

