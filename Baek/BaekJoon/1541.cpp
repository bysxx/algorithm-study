#include <bits/stdc++.h>

using namespace std;

int main()
{
    string expression;
    cin >> expression;

    string numberText = "";
    vector<int> numberVec = { 0 };

    for (string::iterator it = expression.begin(); it != expression.end(); it++)
    {
        if (*it == '+')
        {
            numberVec.back() += stoi(numberText);

            numberText.clear();
        }
        else if (*it == '-')
        {
            numberVec.back() += stoi(numberText);
            numberVec.push_back(0);

            numberText.clear();
        }
        else
        {
            numberText += *it;
        }
    }

    numberVec.back() += stoi(numberText);

    int answer = numberVec[0];
    int size = numberVec.size();

    for (int i = 1; i < size; i++)
    {
        answer -= numberVec[i];
    }

    cout << answer << endl;
}