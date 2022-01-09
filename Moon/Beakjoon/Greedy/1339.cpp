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
			
			if (it == valueMap.end()) // Map�� ���� �������� ������ ���� �߰�
			{
				valueMap.insert(make_pair(word[j], coeff));
			}
			else // Map�� ���� �����ϴ� ��� coeff��ŭ ���Ѵ�
			{
				it->second += coeff;
			}
		}
	}

	// Map�� value�� ���ؼ� �������� �����ϱ� ���� ���ͷ� ����
	vector<pair<char, int>> v(valueMap.begin(), valueMap.end());
	sort(v.begin(), v.end(), cmp);

	// ����� ū ����(key)���� 9 -> 0���� ����ġ �ο� �� ���Ѵ�
	for (auto it = v.begin(); it != v.end(); it++)
	{
		max += priority * it->second;
		priority--;
	}

	cout << max;

	return 0;
}