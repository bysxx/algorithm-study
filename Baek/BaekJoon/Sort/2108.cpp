#include <bits/stdc++.h>

using namespace std;
using std::map;

int GetAverage(vector<int> numVec)
{
	float sum = 0;

	for (int i = 0; i < numVec.size(); i++)
	{
		sum += numVec[i];
	}

	return round(sum / numVec.size());
}

int GetMedian(vector<int> numVec)
{
	sort(numVec.begin(), numVec.end());

	return numVec[(numVec.size() - 1) / 2];
}

int GetMode(vector<int> numVec)
{
	map<int, int> numMap; // Number, Count

	for (int i = 0; i < numVec.size(); i++)
	{
		int num = numVec[i];

		if (numMap.find(num) == numMap.end()) // 못찾음
		{
			numMap.insert({num, 1});
		}
		else
		{
			numMap[num]++;
		}
	}

	int max = 0;
	vector<int> modeVec;

	for (auto iter = numMap.begin(); iter != numMap.end(); ++iter) 
	{
		if (max < iter->second)
		{
			modeVec.clear();
			modeVec.push_back(iter->first);

			max = iter->second;
		}
		else
		{
			modeVec.push_back(iter->first);
		}
	}

	if (modeVec.size() == 1)
	{
		return modeVec[0];
	}
	else
	{
		sort(modeVec.begin(), modeVec.end());

		return modeVec[1];
	}
}

int GetRange(vector<int> numVec)
{
	return *max_element(numVec.begin(), numVec.end()) - *min_element(numVec.begin(), numVec.end());
}

int main()
{
	int number;
	cin >> number;

	vector<int> numVec;
	int tmp;

	for (int i = 0; i < number; i++)
	{
		cin >> tmp;
		numVec.push_back(tmp);
	}

	cout << GetAverage(numVec) << endl;
	cout << GetMedian(numVec) << endl;
	cout << GetMode(numVec) << endl;
	cout << GetRange(numVec) << endl;
}