// https://www.acmicpc.net/problem/2178
// DFS/BFS_2 [01/11]

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int bfs(int x, int y, vector<vector<int>>& maze)
{
	queue<pair<int, int>> q;
	int distance = 1;
	int xDirection[4] = { 1, 0, -1, 0 };
	int yDirection[4] = { 0, 1, 0, -1 };
	int nx, ny;

	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) // ���� ĭ�� ���� �����¿�� Ž��
		{
			nx = x + xDirection[i];
			ny = y + yDirection[i];
			
			if (nx < 0 || nx >= maze.size() || ny < 0 || ny >= maze[0].size()) // �̷��� ������ ����� ���
			{
				continue;
			}

			if (maze[nx][ny] == 1) // ������ 1�� ���� �ְ� ������ �湮�� ���(�̹� �湮�� ��� 1���� ũ��)
			{
				q.push(make_pair(nx, ny));
				maze[nx][ny] = maze[x][y] + 1; // ���� ĭ������ �Ÿ� + 1
				
				if (nx == maze.size()-1 && ny == maze[0].size()-1)
				{
					return maze[nx][ny];
				}
			}
		
		}

		/*
		BFS level�� �ƴ� pop�� ������ while���� �ݺ��Ǳ⿡
		�ݺ��� ����ø��� �Ÿ��� 1�� �ø��� �Ÿ��� �ߺ� �����
		*/
	}

	return -1; // ������ ���� ���� ���·� BFS ����
}

int main(void)
{
	int N, M, i;
	cin >> N >> M;
	string row;

	vector<vector<int>>maze(N, vector<int>(M, 0));

	for (i = 0; i < N; i++)
	{
		cin >> row;
		for (int j = 0; j < M; j++)
		{
			maze[i][j] = row[j] - '0';
		}
	}

	//vector<vector<int>> visited(maze); ���� ���� �� deep copy�Ǿ� visited���� ������ ���� maze���� �ݿ���

	int distance = bfs(0, 0, maze);
	cout << distance;

	return 0;
}

// cf. ó���� (0,0)���� ��������� �湮 ó���� �Ǿ����� �ʾ� 3���� ��µǳ�
// M, N >= 2 �̱⿡ ���� �ذῡ�� ������ ��ġ�� ����.
