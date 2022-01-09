// https://www.acmicpc.net/problem/11399
// �׸���_1 [01/03]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	int people, i, duration;
	int totalTime = 0;
	vector<int> requiredTime; // ���κ� �ҿ� �ð��� ������ ����

	cin >> people;
	requiredTime.reserve(people);

	for (i = 0; i < people; i++)
	{
		cin >> duration;
		requiredTime.push_back(duration);
	}

	// �տ� ��ġ�� ����� �ҿ� �ð��� �������� ��� �ð��� �۾��� ���� �۾�����
	sort(requiredTime.begin(), requiredTime.end()); 

	for (i = 0; i < requiredTime.size(); i++) { 
		totalTime += (people - i) * requiredTime[i]; // �Ϲ��� a_k = (n-k) * a_k
	}

	cout << totalTime;

	return 0;
}