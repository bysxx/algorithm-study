// https://www.acmicpc.net/problem/2206
// DFS/BFS_3 [01/15] ���ذ�

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool flag = false;
vector<vector<bool>> visited;
int shortestDist;

bool bfs(int x, int y, vector<vector<int>>& graph, int distance);

typedef struct _state
{
	int xPos;
	int yPos;
	int curDist;
} curState;

int main(void)
{
	int N, M;
	int distance = 0;
	string row;

	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> row;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = row[j] - '0';
		}
	}

	shortestDist = N * M; // min ���ϱ� ���� �ִ밪 ����

	bool arrived = bfs(0, 0, map, distance);
	
	if (arrived)
		cout << shortestDist;
	else
		cout << "-1";
	return 0;
}

bool bfs(int x, int y, vector<vector<int>>& graph, int distance)
{
	queue <curState> q;
	q.push({ x, y, 1});
	int xDirection[4] = { 1, 0, -1, 0 };
	int yDirection[4] = { 0, 1, 0, -1 };
	int nx, ny;

	while (!q.empty())
	{
		curState cur = q.front();
		x = cur.xPos;
		y = cur.yPos;

		for (int i = 0; i < 4; i++)
		{
			nx = x + xDirection[i];
			ny = y + yDirection[i];

			if (nx < 0 || ny < 0 || nx >= graph.size() || ny >= graph[0].size())
			{
				continue;
			}

			if (graph[nx][ny] == 0 && visited[nx][ny] == false) // ���� �湮
			{
				curState next;
				
				next.curDist = cur.curDist + 1;
				next.xPos = nx;
				next.yPos = ny;

				if (nx == graph.size() - 1 && ny == graph[0].size() - 1) // ����
				{
					if (distance < shortestDist)
						shortestDist = distance; // ���� ��Ʈ�� ����� �Ÿ��� �ּڰ� �� �� ����
					//return shortestDist;
				}

				q.push(next);

				visited[nx][ny] = true;
				cout << x << ", " << y<< "dist: " << distance <<  endl;

			}

			else if (graph[nx][ny] == 0 && visited[nx][ny] == true) // �̹� �湮
			{
				continue;
			}

			else if (graph[nx][ny] == 1 && flag == false) // ó������ �� ������ ���
			{
				// 0�̶�� ���� �� bfs ����
				graph[nx][ny] = 0;
				//visited[x][y] = true; ��ͷ� ���� ���� �״�� false����
				flag = true;

				// ������ ���� ��ȸ �� ���� ������ �����ϱ� ���� ���� ���¸� �ӽ÷� ����
				int tempDist = distance;
				vector<vector<bool>> tempVisited = visited;
				cout << distance << endl;

				int recDist = bfs(nx, ny, graph, distance);

				 // ���� ������ ����
		
				flag = false;
				graph[nx][ny] = 1;
				visited = tempVisited;
				visited[nx][ny] = true;
				distance = tempDist;
		
			}

			else if (graph[nx][ny] == 1 && flag == true) // �̹� ���� �μ��� �̵��� ���
			{
				continue;
			}

			else {
				cout << "�ٸ� ��Ȳ ����" << endl;
				continue;
			}


		}


	}

	return -1;
}
