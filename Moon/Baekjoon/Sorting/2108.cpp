#define _CRT_SECURE_NO_WARNINGS
// https://www.acmicpc.net/problem/2108
// Sorting_3 [01/23]

/* 
*  [Count Sort (계수 정렬)]
*  특정한 조건에서 데이터 개수가 N, 최댓값이 K일 때 O(N+K)로 비교적 작은 시간복잡도를 보장한다.
*  "데이터의 크기 범위가 제한되어 정수 형태로 표현할 수 있을 때"만 사용 가능하다.
*  일반적으로 가장 큰 데이터와 가장 작은 데이터 차이가 1,000,000을 넘지 않을때 효과적으로 사용 가능하다.(공간복잡도)
*  중복된 값이 있는 경우도 index의 값을 늘리면 되기 때문에 사용 가능하다.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int N;
	int numbers[8001] = { 0, };
	int num;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		numbers[4000 + num]++; // -4000부터 4000을 index 0부터 8000에 저장
	}

	double sum = 0;
	int average;

	int middleIdx = 0;
	int middleNum;
	
	int maxFrequency = 0;
	vector<int> modes;
	int mode;

	int smallestNum;
	int biggestNum;
	int range;

	// 산술평균, 최빈값
	for (int i = 0; i < 8001; i++)
	{
		sum += (numbers[i] * (i-4000));
		
		if (numbers[i] > maxFrequency)
		{
			modes.clear();
			modes.push_back(i-4000);
			maxFrequency = numbers[i];
		}
		else if (numbers[i] == maxFrequency)
		{
			modes.push_back(i-4000);
		}
	}

	average = int(round(sum / N));

	if (modes.size() == 1)
		mode = modes[0];
	else
		mode = modes[1];

	// 중앙값
	for (int i = 0; i < 8001; i++)
	{
		middleIdx += numbers[i];
		if (middleIdx > N / 2) // ex. 11개 원소의 중앙값 index =  [11/2] + 1 = 6번째 index
		{	
			middleNum = i-4000;
			break;
		}
	}

	// 범위
	for (int i = 0; i < 8001; i++)
	{
		if (numbers[i] > 0)
		{
			smallestNum = i - 4000;
			break;
		}
	}

	for (int i = 8000; i >= 0; i--)
	{
		if (numbers[i] > 0)
		{
			biggestNum = i - 4000;
			break;
		}
	}
	range = biggestNum - smallestNum;



	printf("%d\n%d\n%d\n%d", average, middleNum, mode, range);

	return 0;
}


