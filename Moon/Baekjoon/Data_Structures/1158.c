// www.acmicpc.net/problem/1158 using Linked List
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node {
	int data;
	struct _node* next;
} Node;

typedef struct _CLL {
	Node* tail;
	Node* cur;
	Node* before;
	int len;
} CList;

void ListInit(CList* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->len = 0;
}


void LInsert(CList* plist, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {  // 저장된 노드가 없는 경우
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;  // 새 노드와 기존의 첫 노드 연결
		plist->tail->next = newNode;  // 기존의 마지막 노드와 새 노드(새로운 첫 노드) 연결
		plist->tail = newNode;  // tail을 기존의 마지막 노드 주소에서 newNode의 주소로 변경
	}

	(plist->len)++;

}

int LFirst(CList* plist, int* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;  // before는 꼬리를 가리키게 한다
	plist->cur = plist->tail->next;  // cur는 머리를 가리키게 한다

	*pdata = plist->cur->data;  // cur가 가리키는 data값 반환 가능
	return TRUE;
}

int LNext(CList* plist, int* pdata) {
	if (plist->tail == NULL) {
		return FALSE;
	}

	plist->before = plist->cur;  // before가 다음 노드를 가리키게 한다
	plist->cur = plist->cur->next;  // cur가 다음 노드를 가리키게 한다

	*pdata = plist->cur->data;  // cur가 가리키는 data값 반환 가능
	return TRUE;
}


int LRemove(CList* plist) {
	Node* rpos = plist->cur;
	int rdata = rpos->data;

	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next) { // 저장된 노드가 1개인 경우
			plist->tail = NULL;
		}
		else  // 삭제할 노드가 마지막 노드인 경우
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;  // before 와 cur 다음 노드 연결
	plist->cur = plist->before;  // cur 위치 재조정
	// 현재는 cur, before 같은 주소를 가리키지만 LFirst() 호출 시 초기화됨

	free(rpos);
	(plist->len)--;

	return rdata;

}

int main(void) {

	CList list;
	int data, totalNum, Kth;
	int flag = 0;
	ListInit(&list);

	scanf("%d %d", &totalNum, &Kth);

	for (int i = 1; i <= totalNum; i++) {
		LInsert(&list, i);
	}

	printf("<");

	if (list.len != 0) {

		if (flag == 0) { // 최초에는 LFisrt(), 이후에는 LNext()로 순회
			LFirst(&list, &data);
			for (int i = 0; i < Kth - 1; i++){ // LFirst() 제외하고 K-1번 순회후 노드 제거
				LNext(&list, &data);
			}
			LRemove(&list);

			if (list.len == 0) { printf("%d", data); }
			else { printf("%d, ", data); }
			
			flag = 1;
		}

		while (LNext(&list, &data)) // 다음 노드가 존재하거나 다음 노드가 없을 때
		{ 
			for (int i = 0; i < Kth - 1; i++){ // while 조건문에서 1번, for 문으로 K-1번 순회 후 노드 제거
				LNext(&list, &data);
			}
			LRemove(&list);

			if (list.len == 0) { printf("%d", data); }
			else { printf("%d, ", data); }
		}
	}

	printf(">");

	return 0;
}