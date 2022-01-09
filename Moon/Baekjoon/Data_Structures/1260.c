// https://www.acmicpc.net/problem/1260
// Stack, Queue, Linked List(w Dummy Node)를 이용한 Graph의 DFS와 BFS(탐색의 우선 순위가 있는 경우)
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
	pstack->stackArr[pstack->topIndex] = data;  // index 증가 후 데이터 저장
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
	return ((pqueue->rear + 1) % QUEUE_LEN == pqueue->front); // rear 바로 다음이 front인 경우
}

void Enqueue(Queue* pqueue, int data)
{
	if (QIsFull(pqueue)) {
		printf("Queue is full");
		//exit(-1);
	}
	else {
		pqueue->rear = (pqueue->rear + 1) % QUEUE_LEN; // rear+1 == MAX_SIZE 이면 rear = 0
		pqueue->queArr[pqueue->rear] = data; // rear 한 칸 이동한 뒤 데이터 저장
	}
}

Data Dequeue(Queue* pqueue)
{
	if (QIsEmpty(pqueue)) {
		printf("Queue is empty");
		//exit(-1);
	}
	else {
		pqueue->front = (pqueue->front + 1) % QUEUE_LEN; // front+1 == MAX_SIZE 이면 front = 0
		return pqueue->queArr[pqueue->front]; // front 한 칸 이동한 뒤 가리키는 데이터 반환하고 삭제
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
	if (plist->comp == NULL) // 정렬 기준 X
		FInsert(plist, data);
	else // 정렬 기준 O
		SInsert(plist, data);
}

int LFirst(List* plist, int* pdata) {

	if (plist->head->next == NULL) // 저장된 노드가 없는 경우
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;  // before는 head, cur는 head->next로 초기화

	*pdata = plist->cur->data;  // cur가 가리키는 값 pdata로 참조 가능
	return TRUE;
}

int LNext(List* plist, int* pdata)
{
	if (plist->cur->next == NULL) // 다음 노드가 없는 경우
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next; // cur와 before 한 칸씩 이동

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

// Linked List의 정렬 기준을 정의하는 함수
void SetSortRule(List* plist, int (*comp)(Data d1, Data d2))
{
	plist->comp = comp;
}

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0; // d1의 정렬 순서가 d2보다 앞서면 0 반환
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

// 방문 유무를 확인 후 데이터를 출력하는 함수
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
	SPush(&stack, visitV); // 시작 정점 저장

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) // visitV와 연결된 정점의 방문을 시도
	{
		int visitFlag = FALSE;

		// 현재 방문하고 있는 visitV와 연결된 정점이 nextV에 저장된 상태(LFirst)

		if (VisitVertex(pg, nextV) == TRUE) // nextV를 최초로 방문 (방문 성공)
		{
			SPush(&stack, visitV);
			visitV = nextV; // visitV를 nextV로 바꾼 뒤 같은 과정 반복(DFS)
			visitFlag = TRUE;
		}

		else // 이미 nextV를 방문함 (방문 실패)
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) // LFirst 이외에 연결된 정점의 방문을 시도
			{
				if(VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;  // visitV를 nextV로 바꾼 뒤 같은 과정 반복(DFS)
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) // 추가로 방문한 노드가 없는 경우
		{
			if (SIsEmpty(&stack)) // 시작점에 되돌아왔으므로 종료
				break; 
			else
				visitV = SPop(&stack); // 해당 노드에서 탐색이 끝났으므로 길을 되돌아간다
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
	InitGraph(&graph, nodes+1); // Linked List의 index는 0~N-1, 정점 번호는 1~N (Null Pointer Exception 방지)

	for (int i = 0; i < edges; i++) {
		scanf("%d %d", &fromNode, &toNode);
		AddEdge(&graph, fromNode, toNode);
	}

	DFS(&graph, startVertex);
	printf("\n");
	BFS(&graph, startVertex);

	return 0;
}