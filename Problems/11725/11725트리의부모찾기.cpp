#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
const int MAX = 100000;
vector<int> a[MAX + 1];
bool check[MAX + 1];
int parent[MAX + 1];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) // 노드의 개수가 n일 때 트리의 간선의 개수는 n - 1개
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	queue<int> q;
	q.push(1); // 루트가 1이라고 정했으므로 1부터 탐색 시작
	check[1] = true;

	while (!q.empty()) // bfs탐색
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < a[node].size(); i++) // 각 노드의 모든 인접 노드 탐색
		{
			int next = a[node][i];
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				parent[next] = node; // 부모 노드 지정
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}
	
}