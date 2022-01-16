#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[101][101];
pair<int, int> direction[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} }; // 동서남북

int bfs(int x, int y)
{
    graph[x][y] = 0; // 시작 위치는 다시 돌아오지 못하도록

    queue<pair<int, int>> bfsQueue;
    bfsQueue.push({ x, y });

    while (bfsQueue.empty() == false)
    {
        int posX = bfsQueue.front().first;
        int posY = bfsQueue.front().second;
        bfsQueue.pop();

        for (int i = 0; i < 4; i++)
        {
            int newPosX = posX + direction[i].first;
            int newPosY = posY + direction[i].second;

            if (graph[newPosX][newPosY] == 1)
            {
                bfsQueue.push({ newPosX, newPosY });

                graph[newPosX][newPosY] = graph[posX][posY] + 1;
            }
        }
    }

    return graph[n - 1][m - 1] + 1; // 시작 위치부터 Count
}

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    cout << bfs(0, 0) << endl;
}