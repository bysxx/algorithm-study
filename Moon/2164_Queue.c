#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 500001

typedef struct _queue {
	int front;
	int rear;
	int data[MAX_SIZE]; // ���� ť�� ũ�� = ������ �� + 1
}Queue;


void InitQueue(Queue* pqueue) {
	pqueue->front = 0;
	pqueue->rear = 0;
}

int IsEmpty(Queue* pqueue) {
	if (pqueue->front == pqueue->rear) { // front == rear�� ���
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int IsFull(Queue* pqueue) {
	if ((pqueue->rear + 1) % MAX_SIZE == pqueue->front) { // rear �ٷ� ������ front�� ���
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
		pqueue->rear = (pqueue->rear + 1) % MAX_SIZE; // rear+1 == MAX_SIZE �̸� rear = 0
		pqueue->data[pqueue->rear] = data; // rear �� ĭ �̵��� �� ������ ����
		//printf("Enquque: %d\n", pqueue->data[pqueue->rear]);
	}
}

int Dequeue(Queue* pqueue) {
	if (IsEmpty(pqueue)) {
		printf("Queue is empty");
		return -1;
	}
	else {
		pqueue->front = (pqueue->front +1) % MAX_SIZE; // front+1 == MAX_SIZE �̸� front = 0
		//printf("Dequeue: %d\n", pqueue->data[pqueue->front]);
		return pqueue->data[pqueue->front]; // front �� ĭ �̵��� �� ����Ű�� ������ ��ȯ�ϰ� ����
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

	while (queue.rear != queue.front + 1) { // ť�� ũ�Ⱑ 1�� �� ������
		Dequeue(&queue); // ���� �� ī�带 ����
		Enqueue(&queue, Dequeue(&queue)); // ���� �� ī�带 ���� �Ʒ��� �̵�
	}

	printf("%d", Dequeue(&queue));

	return 0;
}
