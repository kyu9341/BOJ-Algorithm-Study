#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
vector<int> a[3001];
int dist[3001];
int check[3001]; // 0 : 방문 x , 1 : 방문, 2 : 사이클

int dfs(int node, int p) // p : 이전 노드
{	// -2 : 사이클을 찾았지만 사이클에 포함되지 않는 경우
	// -1 : 사이클을 찾지 못한 경우
	// 0 ~ n - 1 : 사이클을 찾은 경우 (사이클의 시작 인덱스)

	if (check[node] == 1) return node; // 처음으로 방문했던 노드를 다시 만났다면 사이클의 시작점
	check[node] = 1; // 방문 처리
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (next != p) // 이전 노드로는 가지 않음
		{
			int res = dfs(next, node);
			if (res == -2) return -2;
			if (res >= 0) // 사이클을 찾은 경우(사이클 시작 노드)
			{
				check[node] = 2; // 사이클에 포함
				if (node == res) return -2; // 사이클의 시작점을 찾았다면 여기부턴 사이클이 아님
				else return res; // 사이클 시작 노드를 리턴
			}
		}
	}
	return -1; // 사이클을 찾지 못함
}

int main(void)
{
	int n; // 역의 개수
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	dfs(1, -1); // dfs로 사이클의 포함여부를 모두 구함
	
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 2) // 사이클에 포함된 경우
		{
			dist[i] = 0; // 사이클과의 거리는 0
			q.push(i);
		}
		else
		{
			dist[i] = -1;
		}
	}

	while (!q.empty()) // bfs로 사이클과이 거리를 구함
	{ 
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (dist[next] == -1) // 다음 노드가 사이클에 포함되어있지 않다면
			{
				q.push(next);
				dist[next] = dist[node] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << '\n';
}