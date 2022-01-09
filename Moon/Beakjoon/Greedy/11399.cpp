// https://www.acmicpc.net/problem/11399
// 그리디_1 [01/03]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	int people, i, duration;
	int totalTime = 0;
	vector<int> requiredTime; // 개인별 소요 시간을 저장한 벡터

	cin >> people;
	requiredTime.reserve(people);

	for (i = 0; i < people; i++)
	{
		cin >> duration;
		requiredTime.push_back(duration);
	}

	// 앞에 위치한 사람의 소요 시간이 작을수록 대기 시간이 작아져 합이 작아진다
	sort(requiredTime.begin(), requiredTime.end()); 

	for (i = 0; i < requiredTime.size(); i++) { 
		totalTime += (people - i) * requiredTime[i]; // 일반항 a_k = (n-k) * a_k
	}

	cout << totalTime;

	return 0;
}