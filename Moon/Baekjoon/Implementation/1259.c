//https://www.acmicpc.net/problem/1259
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main() {
	int digits[5] = { 0, };
	int number;
	int j, l;
	int flag = 1;  // 1: yes, 0: no
	
	while (1) {

		scanf("%d", &number);  // 1 <= number <= 99999
		if (number == 0)
			break;
		
		for (int i = 0; i < 5; i++) {  // 각 digit 받아서 array에 저장
			int remainder = number % (int)pow(10, i+1);
			digits[4-i] = remainder / (int)pow(10, i);
		}

		j = 0;
		while (digits[j] == 0) {
			j++;  // 시작하는 자리수 얻기
		}

		l = 1;
		for (int k = j; k < 5-l; k++) {
			//printf("%d %d\n", digits[k], digits[5-l]);
			if (digits[k] != digits[5 - l]) {  // 양쪽 끝부터 자리수 비교
				flag = 0;
			}
			l++;
		}
		
		if (flag==1) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}

		/*for (int i = 0; i < 5; i++) {
			printf("%d ", digits[i]);
		}*/
		
		flag = 1;
	}

	return 0;
}
