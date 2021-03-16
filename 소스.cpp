#include "myvector.h"

struct queue {
	struct vector* vec;
};

struct queue* queue_create();
void queue_destructor(struct queue* q);

void queue_push(struct queue* q, int value);
void queue_pop(struct queue* q);
int queue_size(struct queue* q);
int queue_empty(struct queue* q);
int queue_front(struct queue* q);
int queue_back(struct queue* q);

int main() {
	struct queue* q = queue_create();
	int n,k;
	scanf_s("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		queue_push(q,i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++) {
			queue_push(q, queue_front(q));
			queue_pop(q);
		}
		printf("%d ", queue_front(q));
		queue_pop(q);
	}

}

struct queue* queue_create() {
	struct queue* new_q = (struct queue*)malloc(sizeof(struct queue));
	new_q->vec = vector_create();

	return new_q;
}

void queue_destructor(struct queue* q) {
	vector_destructor(q->vec);
	free(q);
}

void queue_push(struct queue* q, int value) {
	vector_push_back(q->vec, value);
}

void queue_pop(struct queue* q) {
	if (queue_empty(q) == 0)
		vector_erase(q->vec, 0);
}

int queue_size(struct queue* q) {
	return vector_size(q->vec);
}

int queue_empty(struct queue* q) {
	return vector_empty(q->vec);
}

int queue_front(struct queue* q) {
	return *vector_front(q->vec);
}

int queue_back(struct queue* q) {
	return *vector_back(q->vec);
}
