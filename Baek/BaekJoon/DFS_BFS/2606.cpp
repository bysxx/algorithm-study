#include <bits/stdc++.h>

using namespace std;

vector<bool> isVisited(101);
vector<int> graph[101];

void dfs(int x)
{
    isVisited[x] = true;

    for (int i = 0; i < graph[x].size(); i++)
    {
        if (isVisited[graph[x][i]] == false)
        {
            dfs(graph[x][i]);
        }
    }
}

int main()
{
    int computerNum;
    int connectNum;
    cin >> computerNum >> connectNum;

    int a, b;

    for (int i = 0; i < connectNum; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    int answer = 0;

    for (int i = 2; i < computerNum; i++) // 1번은 제외기 때문에 2부터 시작
    {
        if (isVisited[i] == true)
        {
            answer++;
        }
    }

    cout << answer;
}