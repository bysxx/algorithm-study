#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 500001

typedef struct _queue {
	int front;
	int rear;
	int data[MAX_SIZE]; // 원형 큐의 크기 = 데이터 수 + 1
}Queue;


void InitQueue(Queue* pqueue) {
	pqueue->front = 0;
	pqueue->rear = 0;
}

int IsEmpty(Queue* pqueue) {
	if (pqueue->front == pqueue->rear) { // front == rear인 경우
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int IsFull(Queue* pqueue) {
	if ((pqueue->rear + 1) % MAX_SIZE == pqueue->front) { // rear 바로 다음이 front인 경우
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void Enqueue(Queue* pqueue, int data) {
	if (IsFull(pqueue)) {
		printf("Queue is full");
	}
	else {
		pqueue->rear = (pqueue->rear + 1) % MAX_SIZE; // rear+1 == MAX_SIZE 이면 rear = 0
		pqueue->data[pqueue->rear] = data; // rear 한 칸 이동한 뒤 데이터 저장
		//printf("Enquque: %d\n", pqueue->data[pqueue->rear]);
	}
}

int Dequeue(Queue* pqueue) {
	if (IsEmpty(pqueue)) {
		printf("Queue is empty");
		return -1;
	}
	else {
		pqueue->front = (pqueue->front +1) % MAX_SIZE; // front+1 == MAX_SIZE 이면 front = 0
		//printf("Dequeue: %d\n", pqueue->data[pqueue->front]);
		return pqueue->data[pqueue->front]; // front 한 칸 이동한 뒤 가리키는 데이터 반환하고 삭제
	}
}

int main(void) {
	
	int cards;
	Queue queue;
	InitQueue(&queue);

	scanf("%d", &cards);


	for (int i = 1; i <= cards; i++) {
		Enqueue(&queue, i);
	}

	while (queue.rear != queue.front + 1) { // 큐의 크기가 1이 될 때까지
		Dequeue(&queue); // 가장 위 카드를 제거
		Enqueue(&queue, Dequeue(&queue)); // 가장 위 카드를 가장 아래로 이동
	}

	printf("%d", Dequeue(&queue));

	return 0;
}
