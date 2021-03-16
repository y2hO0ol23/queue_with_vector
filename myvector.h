#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct vector {
	int* data;
	int size;
	int capacity;
};

struct vector* vector_create();
struct vector* vector_copy(struct vector* vec);
void vector_destructor(struct vector* vec);
void vector_reserve(struct vector* vec, int capacity);
void vector_resize(struct vector* vec, int size);
void vector_shrink(struct vector* vec);

int vector_size(struct vector* vec);
int vector_capacity(struct vector* vec);
int vector_empty(struct vector* vec);

int* vector_at(struct vector* vec, int pos);
int* vector_front(struct vector* vec);
int* vector_back(struct vector* vec);
void vector_swap(struct vector* vec, int lhs, int rhs);

void vector_insert(struct vector* vec, int pos, int value);
void vector_push_back(struct vector* vec, int value);
void vector_erase(struct vector* vec, int pos);
void vector_pop_back(struct vector* vec);
void vector_clear(struct vector* vec);

void vector_print(struct vector* vec);

#endif