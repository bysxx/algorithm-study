#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef pair<char, int> ci;

int main()
{
    int number;
    cin >> number;

    vector<string> alphabetVec(number);
    string alphabetNumber;

    for (int i = 0; i < number; i++)
    {
        cin >> alphabetNumber;

        alphabetVec.push_back(alphabetNumber);
    }

    map<char, int> alphabetMap;

    for (int i = 0; i < alphabetVec.size(); i++)
    {
        int index = alphabetVec[i].length() - 1;

        for (string::iterator it = alphabetVec[i].begin(); it != alphabetVec[i].end(); it++)
        {
            if (alphabetMap.find(*it) != alphabetMap.end()) // 같은 값이 있으면
            {
                alphabetMap[*it] += pow(10, index);
            }
            else
            {
                alphabetMap.insert({ *it, pow(10, index) });
            }

            index--;
        }
    }

    vector<ci> alphabetMapToVec(alphabetMap.begin(), alphabetMap.end());

    sort(alphabetMapToVec.begin(), alphabetMapToVec.end(), [](ci a, ci b)
    {
        return a.second > b.second;
    });

    int answer = 0;

    for (int i = 0; i < alphabetMapToVec.size(); i++)
    {
        answer += alphabetMap[alphabetMapToVec[i].first] * (9 - i);
    }
    
    cout << answer;
}