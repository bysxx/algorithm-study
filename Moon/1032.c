#https://www.acmicpc.net/problem/1032
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// char array�� ũ�⸦ ��ȯ�ϴ� �Լ�
int getStringLength(char str[]) {
	int len=0;
	
	while (str[len] != 0) {
		len++;
	}

	return len;
}


int main() {
	int numOfFiles;
	int strLen;
	char formerString[50] = ""; // ù ���ϸ�
	char latterString[50] = ""; // �� ���ϸ�


	scanf("%d ", &numOfFiles);
	scanf("%s", formerString);

	strLen = getStringLength(formerString);
	//printf("len: %d\n", strLen);

	for (int i = 0; i < numOfFiles-1; i++) {
		scanf("%s", latterString);
		// ù ���ϸ�� �� ���ϸ��� �ٸ� ��� ù ���ϸ� ����
		for (int j = 0; j < strLen; j++) {
			if (formerString[j] != latterString[j]) { 
				formerString[j] = '?';
			}
		}
		
	}
	printf("%s", formerString); // ������ ���ϸ��� ���ϰ� ��ġ

	return 0;
}