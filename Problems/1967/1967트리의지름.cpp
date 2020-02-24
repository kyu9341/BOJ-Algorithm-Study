#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
const int MAX = 100000;
vector<pair<int, int>> a[MAX + 1];
bool check[MAX + 1];
int dist[MAX + 1];
int n; // 정점의 개수

pair<int, int> bfs(int start)
{
	memset(dist, 0, sizeof(dist));
	memset(check, false, sizeof(check));

	queue<int> q;
	q.push(start);
	check[start] = true;
	dist[start] = 0; // 시작 노드의 거리는 0

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i].first;
			int ndist = a[node][i].second;
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				dist[next] = dist[node] + ndist; // 시작점과의 거리를 저장
			}
		}
	}
	int max = 0;
	int index;
	for (int i = 1; i <= n; i++)
	{
		if (max < dist[i])
		{
			max = dist[i];
			index = i;
		}
	}
	return { index, max }; // 가장 먼 거리와 그 인덱스를 리턴
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v, d; // d : 거리
		cin >> u >> v >> d;
		a[u].push_back(make_pair(v, d));
		a[v].push_back(make_pair(u, d));
	}

	pair<int, int> tmp = bfs(1); // 어느 한 지점부터 가장 먼 노드를 구함
	pair<int, int> res = bfs(tmp.first); // 그 노드부터 다시 가장 먼 노드까지의 거리가 정답

	cout << res.second << '\n';

}