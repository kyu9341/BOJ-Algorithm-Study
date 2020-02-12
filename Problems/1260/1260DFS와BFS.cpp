#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

bool check[1001];
vector<int> a[1001];

void dfs(int node)
{
	check[node] = true; // 현재 노드 방문 처리
	cout << node << ' ';
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i]; // 다음에 방문할 노드 번호를 저장
		if (!check[next]) // 다음 노드가 방문하지 않았다면
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	memset(check, false, sizeof(check)); // 메모리 초기화
	check[start] = true;
	q.push(start); // 큐에 시작 노드 push
	while (!q.empty()) // 큐가 비어있지 않으면 반복
	{
		int node = q.front(); // 큐의 맨 앞 원소
		q.pop(); // 큐에서 제거
		cout << node << ' '; // 출력
		for (int i = 0; i < a[node].size(); i++) // 현재 노드와 연결된 노드를 확인
		{
			int next = a[node][i];
			if (!check[next]) // 방문하지 않은 노드면
			{
				check[next] = true; // 방문 처리 후
				q.push(next); // 큐에 push
			}
		}
	}
}

int main(void)
{
	int n, m, start;
	cin >> n >> m >> start;

	while (m--)
	{
		int u, v; // 연결되는 두 정점
		cin >> u >> v;

		a[u].push_back(v); // 두 정점을 연결시킨다
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		sort(a[i].begin(), a[i].end()); // 각 인접 리스트를 정렬

	dfs(start);
	cout << '\n';
	bfs(start);
	cout << '\n';
}