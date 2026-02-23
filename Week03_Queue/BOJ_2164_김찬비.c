#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#define MAX_QUEUE_SIZE 500001

typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	// exit(1); 
}

void init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		//error("큐가 포화 상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		//error("큐가 공백 상태입니다.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q)) {
		//error("큐가 공백 상태입니다.");
		return -1;
	}
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType* q) {
	return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int last_card(int n) {
	QueueType q;
	init(&q);
	int i, temp;

	for (i = 1; i <= n; i++)
		enqueue(&q, i);

	while (get_count(&q) > 1) {
		dequeue(&q);
		temp = dequeue(&q);
		enqueue(&q, temp);
	}
	return dequeue(&q);
}

int main(void) {
	int n;

	scanf("%d", &n);

	printf("%d", last_card(n));
}
