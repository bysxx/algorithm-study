#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> timeVector(size);

    int cell;

    for (int i = 0; i < size; i++)
    {
        cin >> cell;
        timeVector.push_back(cell);
    }

    sort(timeVector.begin(), timeVector.end());

    int answer = 0;
    int time = 0;

    for (int i = 0; i < size; i++)
    {
        time += timeVector[i];
        answer += time;
    }

    cout << answer << endl;
}