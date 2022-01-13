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

		for (int i = 0; i < 4; i++) // 현재 칸에 대해 상하좌우로 탐색
		{
			nx = x + xDirection[i];
			ny = y + yDirection[i];
			
			if (nx < 0 || nx >= maze.size() || ny < 0 || ny >= maze[0].size()) // 미로의 범위를 벗어나는 경우
			{
				continue;
			}

			if (maze[nx][ny] == 1) // 주위에 1인 곳이 있고 최조로 방문한 경우(이미 방문한 경우 1보다 크다)
			{
				q.push(make_pair(nx, ny));
				maze[nx][ny] = maze[x][y] + 1; // 이전 칸까지의 거리 + 1
				
				if (nx == maze.size()-1 && ny == maze[0].size()-1)
				{
					return maze[nx][ny];
				}
			}
		
		}

		/*
		BFS level이 아닌 pop할 때마다 while문이 반복되기에
		반복문 종료시마다 거리를 1씩 늘리면 거리가 중복 연산됨
		*/
	}

	return -1; // 목적지 도착 못한 상태로 BFS 종료
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

	//vector<vector<int>> visited(maze); 벡터 복사 시 deep copy되어 visited에서 수정한 값이 maze에도 반영됨

	int distance = bfs(0, 0, maze);
	cout << distance;

	return 0;
}

// cf. 처음에 (0,0)에서 출발하지만 방문 처리가 되어있지 않아 3으로 출력되나
// M, N >= 2 이기에 문제 해결에는 영향을 미치지 않음.
