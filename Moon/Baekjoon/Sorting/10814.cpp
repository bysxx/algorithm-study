#define _CRT_SECURE_NO_WARNINGS
// https://www.acmicpc.net/problem/10814
// Sorting_2 [01/23]


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, string>> vec;

bool comp(const pair<int, string> &i, const pair<int, string> &j) {
	return i.first < j.first;
}

int main(void)
{
	int N;
	cin >> N;
	int age;
	string name;

	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		vec.push_back(make_pair(age, name));
	}

	stable_sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", vec[i].first, vec[i].second.c_str());
	}

	return 0;
}


