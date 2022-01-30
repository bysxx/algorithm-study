#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tmp;

    int n;
    cin >> n;
    vector<int> targetVec;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        targetVec.push_back(tmp);
    }

    sort(targetVec.begin(), targetVec.end()); // Target Sort

    int m;
    cin >> m;
    vector<int> inputVec;

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        inputVec.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        if (binary_search(targetVec.begin(), targetVec.end(), inputVec[i]) == true) // BInary Search
        {
            printf("%o\n", 1);
        }
        else
        {
            printf("%o\n", 0);
        }
    }
}