// https://www.acmicpc.net/problem/1339
// Greedy_3 [01/08]

#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int>& a, pair<char, int>& b)
{
	if (a.second == b.second)
		return a.first > b.first;
	else
		return a.second > b.second;
}

int main(void)
{
	int lines, coeff;
	int priority = 9;
	int max = 0;
	string word;
	map<char, int> valueMap;

	cin >> lines;

	for (int i = 0; i < lines; i++)
	{
		cin >> word;
		for (int j = 0; j < word.length(); j++)
		{
			coeff = pow(10, word.length() - 1 - j);
			std::map<char, int>::iterator it = valueMap.find(word[j]);
			
			if (it == valueMap.end()) // Map에 원소 존재하지 않으면 원소 추가
			{
				valueMap.insert(make_pair(word[j], coeff));
			}
			else // Map에 원소 존재하는 경우 coeff만큼 더한다
			{
				it->second += coeff;
			}
		}
	}

	// Map의 value에 대해서 내림차순 정렬하기 위해 벡터로 복사
	vector<pair<char, int>> v(valueMap.begin(), valueMap.end());
	sort(v.begin(), v.end(), cmp);

	// 계수가 큰 문자(key)부터 9 -> 0으로 가중치 부여 후 합한다
	for (auto it = v.begin(); it != v.end(); it++)
	{
		max += priority * it->second;
		priority--;
	}

	cout << max;

	return 0;
}