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

	if (plist->tail == NULL) {  // ����� ��尡 ���� ���
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;  // �� ���� ������ ù ��� ����
		plist->tail->next = newNode;  // ������ ������ ���� �� ���(���ο� ù ���) ����
		plist->tail = newNode;  // tail�� ������ ������ ��� �ּҿ��� newNode�� �ּҷ� ����
	}

	(plist->len)++;

}

int LFirst(CList* plist, int* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;  // before�� ������ ����Ű�� �Ѵ�
	plist->cur = plist->tail->next;  // cur�� �Ӹ��� ����Ű�� �Ѵ�

	*pdata = plist->cur->data;  // cur�� ����Ű�� data�� ��ȯ ����
	return TRUE;
}

int LNext(CList* plist, int* pdata) {
	if (plist->tail == NULL) {
		return FALSE;
	}

	plist->before = plist->cur;  // before�� ���� ��带 ����Ű�� �Ѵ�
	plist->cur = plist->cur->next;  // cur�� ���� ��带 ����Ű�� �Ѵ�

	*pdata = plist->cur->data;  // cur�� ����Ű�� data�� ��ȯ ����
	return TRUE;
}


int LRemove(CList* plist) {
	Node* rpos = plist->cur;
	int rdata = rpos->data;

	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next) { // ����� ��尡 1���� ���
			plist->tail = NULL;
		}
		else  // ������ ��尡 ������ ����� ���
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;  // before �� cur ���� ��� ����
	plist->cur = plist->before;  // cur ��ġ ������
	// ����� cur, before ���� �ּҸ� ����Ű���� LFirst() ȣ�� �� �ʱ�ȭ��

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

		if (flag == 0) { // ���ʿ��� LFisrt(), ���Ŀ��� LNext()�� ��ȸ
			LFirst(&list, &data);
			for (int i = 0; i < Kth - 1; i++){ // LFirst() �����ϰ� K-1�� ��ȸ�� ��� ����
				LNext(&list, &data);
			}
			LRemove(&list);

			if (list.len == 0) { printf("%d", data); }
			else { printf("%d, ", data); }
			
			flag = 1;
		}

		while (LNext(&list, &data)) // ���� ��尡 �����ϰų� ���� ��尡 ���� ��
		{ 
			for (int i = 0; i < Kth - 1; i++){ // while ���ǹ����� 1��, for ������ K-1�� ��ȸ �� ��� ����
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