// https://www.acmicpc.net/problem/1260
// Stack, Queue, Linked List(w Dummy Node)�� �̿��� Graph�� DFS�� BFS(Ž���� �켱 ������ �ִ� ���)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 1000
#define QUEUE_LEN 1000

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} Stack;

typedef struct _circularQueue
{
	int front;
	int rear;
	Data queArr[QUEUE_LEN];
} Queue;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _dummylinkedList
{
	Node* head;
	Node* cur;
	Node* before;
	int len;
	int (*comp)(Data d1, Data d2);
} List;

typedef struct _graph
{
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
} Graph;

// Stack library

void InitStack(Stack* pstack){
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack) {
	return (pstack->topIndex == -1);
}

void SPush(Stack* pstack, Data data) {
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;  // index ���� �� ������ ����
}

Data SPop(Stack* pstack) {
	int rIdx;

	if (SIsEmpty(pstack)) {
		printf("Stack is empty");
		//exit(-1);
	}

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;
	return pstack->stackArr[rIdx];
}

// Circular Queue library

void InitQueue(Queue* pqueue)
{
	pqueue->front = 0;
	pqueue->rear = 0;
}

int QIsEmpty(Queue* pqueue)
{
	return (pqueue->front == pqueue->rear);
}

int QIsFull(Queue* pqueue)
{
	return ((pqueue->rear + 1) % QUEUE_LEN == pqueue->front); // rear �ٷ� ������ front�� ���
}

void Enqueue(Queue* pqueue, int data)
{
	if (QIsFull(pqueue)) {
		printf("Queue is full");
		//exit(-1);
	}
	else {
		pqueue->rear = (pqueue->rear + 1) % QUEUE_LEN; // rear+1 == MAX_SIZE �̸� rear = 0
		pqueue->queArr[pqueue->rear] = data; // rear �� ĭ �̵��� �� ������ ����
	}
}

Data Dequeue(Queue* pqueue)
{
	if (QIsEmpty(pqueue)) {
		printf("Queue is empty");
		//exit(-1);
	}
	else {
		pqueue->front = (pqueue->front + 1) % QUEUE_LEN; // front+1 == MAX_SIZE �̸� front = 0
		return pqueue->queArr[pqueue->front]; // front �� ĭ �̵��� �� ����Ű�� ������ ��ȯ�ϰ� ����
	}
}

// Linked List library (w Dummy Node)

void InitList(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->len = 0;
}

void FInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->len)++;
}

void SInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->len)++;
}

void LInsert(List* plist, Data data)
{
	if (plist->comp == NULL) // ���� ���� X
		FInsert(plist, data);
	else // ���� ���� O
		SInsert(plist, data);
}

int LFirst(List* plist, int* pdata) {

	if (plist->head->next == NULL) // ����� ��尡 ���� ���
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;  // before�� head, cur�� head->next�� �ʱ�ȭ

	*pdata = plist->cur->data;  // cur�� ����Ű�� �� pdata�� ���� ����
	return TRUE;
}

int LNext(List* plist, int* pdata)
{
	if (plist->cur->next == NULL) // ���� ��尡 ���� ���
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next; // cur�� before �� ĭ�� �̵�

	*pdata = plist->cur->data;
	return TRUE;
}

int LRemove(List* plist)
{
	Node* rpos = plist->cur;
	int rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->len)--;

	return rdata;
}

// Linked List�� ���� ������ �����ϴ� �Լ�
void SetSortRule(List* plist, int (*comp)(Data d1, Data d2))
{
	plist->comp = comp;
}

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0; // d1�� ���� ������ d2���� �ռ��� 0 ��ȯ
	else
		return 1;
}

// Graph library

void InitGraph(Graph* pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		InitList(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(Graph* pg) {
	if (pg->adjList != NULL)
		free(pg);
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(Graph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

// �湮 ������ Ȯ�� �� �����͸� ����ϴ� �Լ�
int VisitVertex(Graph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		printf("%d ", visitV);
		return TRUE;
	}
	return FALSE;
}

void DFS(Graph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	InitStack(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV); // ���� ���� ����

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) // visitV�� ����� ������ �湮�� �õ�
	{
		int visitFlag = FALSE;

		// ���� �湮�ϰ� �ִ� visitV�� ����� ������ nextV�� ����� ����(LFirst)

		if (VisitVertex(pg, nextV) == TRUE) // nextV�� ���ʷ� �湮 (�湮 ����)
		{
			SPush(&stack, visitV);
			visitV = nextV; // visitV�� nextV�� �ٲ� �� ���� ���� �ݺ�(DFS)
			visitFlag = TRUE;
		}

		else // �̹� nextV�� �湮�� (�湮 ����)
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) // LFirst �̿ܿ� ����� ������ �湮�� �õ�
			{
				if(VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;  // visitV�� nextV�� �ٲ� �� ���� ���� �ݺ�(DFS)
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) // �߰��� �湮�� ��尡 ���� ���
		{
			if (SIsEmpty(&stack)) // �������� �ǵ��ƿ����Ƿ� ����
				break; 
			else
				visitV = SPop(&stack); // �ش� ��忡�� Ž���� �������Ƿ� ���� �ǵ��ư���
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void BFS(Graph* pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	InitQueue(&queue);
	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{

		if (VisitVertex(pg, nextV) == TRUE) {
			Enqueue(&queue, nextV);
		}

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			if (VisitVertex(pg, nextV) == TRUE) {
				Enqueue(&queue, nextV);
			}

		}

		if (QIsEmpty(&queue) == TRUE) {
			break;
		}
		else
			visitV = Dequeue(&queue);
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

int main(void)
{
	int nodes, edges, startVertex;
	int fromNode, toNode;
	Graph graph;

	
	scanf("%d %d %d", &nodes, &edges, &startVertex);
	InitGraph(&graph, nodes+1); // Linked List�� index�� 0~N-1, ���� ��ȣ�� 1~N (Null Pointer Exception ����)

	for (int i = 0; i < edges; i++) {
		scanf("%d %d", &fromNode, &toNode);
		AddEdge(&graph, fromNode, toNode);
	}

	DFS(&graph, startVertex);
	printf("\n");
	BFS(&graph, startVertex);

	return 0;
}