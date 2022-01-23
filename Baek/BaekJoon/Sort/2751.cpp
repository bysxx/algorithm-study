#include <bits/stdc++.h>

using namespace std;

int main()
{
	int number, tmp;
	cin >> number;
	
	vector<int> numVec;

	for (int i = 0; i < number; i++)
	{
		cin >> tmp;
		numVec.push_back(tmp);
	}

	sort(numVec.begin(), numVec.end());

	for (int i = 0; i < number; i++)
	{
		cout << numVec[i] << '\n';
	}
}