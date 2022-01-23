#define _CRT_SECURE_NO_WARNINGS
// https://www.acmicpc.net/problem/2108
// Sorting_4 [01/19]

/* 
*  [Count Sort (��� ����)]
*  Ư���� ���ǿ��� ������ ������ N, �ִ��� K�� �� O(N+K)�� ���� ���� �ð����⵵�� �����Ѵ�.
*  "�������� ũ�� ������ ���ѵǾ� ���� ���·� ǥ���� �� ���� ��"�� ��� �����ϴ�.
*  �Ϲ������� ���� ū �����Ϳ� ���� ���� ������ ���̰� 1,000,000�� ���� ������ ȿ�������� ��� �����ϴ�.(�������⵵)
*  �ߺ��� ���� �ִ� ��쵵 index�� ���� �ø��� �Ǳ� ������ ��� �����ϴ�.
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
		numbers[4000 + num]++; // -4000���� 4000�� index 0���� 8000�� ����
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

	// ������, �ֺ�
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

	// �߾Ӱ�
	for (int i = 0; i < 8001; i++)
	{
		middleIdx += numbers[i];
		if (middleIdx > N / 2) // ex. 11�� ������ �߾Ӱ� index =  [11/2] + 1 = 6��° index
		{	
			middleNum = i-4000;
			break;
		}
	}

	// ����
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


