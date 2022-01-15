// https://www.acmicpc.net/problem/2206
// DFS/BFS_3 [01/15] 미해결

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

	shortestDist = N * M; // min 구하기 위해 최대값 설정

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

			if (graph[nx][ny] == 0 && visited[nx][ny] == false) // 최초 방문
			{
				curState next;
				
				next.curDist = cur.curDist + 1;
				next.xPos = nx;
				next.yPos = ny;

				if (nx == graph.size() - 1 && ny == graph[0].size() - 1) // 도착
				{
					if (distance < shortestDist)
						shortestDist = distance; // 현재 루트로 계산한 거리의 최솟값 비교 후 저장
					//return shortestDist;
				}

				q.push(next);

				visited[nx][ny] = true;
				cout << x << ", " << y<< "dist: " << distance <<  endl;

			}

			else if (graph[nx][ny] == 0 && visited[nx][ny] == true) // 이미 방문
			{
				continue;
			}

			else if (graph[nx][ny] == 1 && flag == false) // 처음으로 벽 마주한 경우
			{
				// 0이라고 가정 후 bfs 실행
				graph[nx][ny] = 0;
				//visited[x][y] = true; 재귀로 실행 위해 그대로 false유지
				flag = true;

				// 가정에 따른 순회 후 기존 값으로 복귀하기 위해 현재 상태를 임시로 저장
				int tempDist = distance;
				vector<vector<bool>> tempVisited = visited;
				cout << distance << endl;

				int recDist = bfs(nx, ny, graph, distance);

				 // 기존 값으로 복귀
		
				flag = false;
				graph[nx][ny] = 1;
				visited = tempVisited;
				visited[nx][ny] = true;
				distance = tempDist;
		
			}

			else if (graph[nx][ny] == 1 && flag == true) // 이미 벽을 부수고 이동한 경우
			{
				continue;
			}

			else {
				cout << "다른 상황 존재" << endl;
				continue;
			}


		}


	}

	return -1;
}
