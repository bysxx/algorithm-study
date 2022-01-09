#https://www.acmicpc.net/problem/1032
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// char array의 크기를 반환하는 함수
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
	char formerString[50] = ""; // 첫 파일명
	char latterString[50] = ""; // 비교 파일명


	scanf("%d ", &numOfFiles);
	scanf("%s", formerString);

	strLen = getStringLength(formerString);
	//printf("len: %d\n", strLen);

	for (int i = 0; i < numOfFiles-1; i++) {
		scanf("%s", latterString);
		// 첫 파일명과 비교 파일명이 다른 경우 첫 파일명 수정
		for (int j = 0; j < strLen; j++) {
			if (formerString[j] != latterString[j]) { 
				formerString[j] = '?';
			}
		}
		
	}
	printf("%s", formerString); // 수정된 파일명이 패턴과 일치

	return 0;
}