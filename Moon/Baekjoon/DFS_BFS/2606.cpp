// https://www.acmicpc.net/problem/2606
// DFS/BFS_1 [01/10]

#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
int dfs(int x, vector<vector <int>>& graph, int infected);

int main()
{
	int computers, connected, i;
	int com1, com2;
	int infectedCom;

	cin >> computers >> connected;
	vector<vector<int>> networkGraph(computers, vector<int>(computers, 0));

	for (i = 0; i < computers; i++)
	{
		visited.push_back(false);
	}

	for (i = 0; i < connected; i++)
	{
		cin >> com1 >> com2;
		networkGraph[com1-1][com2-1] = 1;
		networkGraph[com2-1][com1-1] = 1;
	}

	infectedCom = dfs(0, networkGraph, 0);

	cout << infectedCom -1; // 1�� ��ǻ�� ����

	return 0;
}

int dfs(int x, vector<vector <int>>& graph, int infected)
{
	for (int i = 0; i < graph[0].size(); i++)
	{
		if (graph[x][i] == 1 && visited[i] == false) { // ��ǻ�ͳ��� ����Ǿ� �ְ�, ó�� �湮�ϴ� ���
			
			infected++;
			visited[i] = true;
			
			infected = dfs(i, graph, infected);
		}
	}

	return infected;
}
