#include "myvector.h"

struct vector* vector_create() {
	struct vector* new_vector = (struct vector*)malloc(sizeof(struct vector));

	new_vector->size = 0;
	new_vector->capacity = 0;

	return new_vector;
}

struct vector* vector_copy(struct vector* vec) {
	int vsize = vector_size(vec);
	struct vector* new_vector = vector_create();

	vector_reserve(new_vector, vsize);

	for (int i = 0; i < vsize; i++)
		vector_push_back(new_vector, *vector_at(vec, i));

	return new_vector;
}

void vector_destructor(struct vector* vec) {
	free(vec->data);
	free(vec);
}

void vector_reserve(struct vector* vec, int capacity) {
	if (vector_capacity(vec) == 0)
		vec->data = (int*)malloc(sizeof(int) * capacity);
	else
		vec->data = (int*)realloc(vec->data, sizeof(int) * capacity);

	vec->capacity = capacity;

	if (vec->size > capacity)
		vec->size = capacity;
}

void vector_resize(struct vector* vec, int size) {
	int vsize = vector_size(vec);
	int vcapacity = vector_capacity(vec);

	if (vsize < size) {
		int loop_size = size - vsize;

		for (int i = 0; i < loop_size; i++)
			vector_push_back(vec, 0);
	}

	vec->size = size;
}

void vector_shrink(struct vector* vec) {
	vector_reserve(vec, vector_size(vec));
}

int vector_size(struct vector* vec) {
	return vec->size;
}

int vector_capacity(struct vector* vec) {
	return vec->capacity;
}

int vector_empty(struct vector* vec) {
	return vector_size(vec) == 0;
}

int* vector_at(struct vector* vec, int pos) {
	return &vec->data[pos];
}

int* vector_front(struct vector* vec) {
	return vector_at(vec, 0);
}

int* vector_back(struct vector* vec) {
	return vector_at(vec, vector_size(vec) - 1);
}

void vector_swap(struct vector* vec, int lhs, int rhs) {
	int temp;
	temp = *vector_at(vec, lhs);
	*vector_at(vec, lhs) = *vector_at(vec, rhs);
	*vector_at(vec, rhs) = temp;
}

void vector_insert(struct vector* vec, int pos, int value) {
	int vsize = vector_size(vec);
	int vcapacity = vector_capacity(vec);

	if (pos > vcapacity) {
	}
	else {
		if (vsize == vsize) {
			if (vcapacity == 0) {
				vec->data = (int*)malloc(sizeof(int));
				vec->capacity = 1;
			}
			else {
				vec->capacity = vcapacity * 2;
				vec->data = (int*)realloc(vec->data, sizeof(int) * vector_capacity(vec));

				for (int i = vsize; i > pos; i--)
					vec->data[i] = vec->data[i - 1];
			}
		}
		else {
			for (int i = vsize; i > pos; i--) {
				vec->data[i] = vec->data[i - 1];
			}
		}

		vec->data[pos] = value;
		vec->size++;
	}
}

void vector_erase(struct vector* vec, int pos) {
	int vsize = vector_size(vec);
	if (pos < vsize) {
		int loop_size = vsize - 1;

		for (int i = pos; i < loop_size; i++)
			vec->data[i] = vec->data[i + 1];

		vec->size--;
	}
}

void vector_push_back(struct vector* vec, int value) {
	vector_insert(vec, vector_size(vec), value);
}

void vector_pop_back(struct vector* vec) {
	vector_erase(vec, vector_size(vec) - 1);
}

void vector_clear(struct vector* vec) {
	vec->size = 0;
}

void vector_print(struct vector* vec) {
	int vsize = vector_size(vec);

	for (int i = 0; i < vsize; i++)
		printf("%d ", *vector_at(vec, i));
}