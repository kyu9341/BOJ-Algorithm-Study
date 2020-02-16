#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int node)
{
	check[node] = true; // 방문 처리

	for (int i = 0; i < a[node].size(); i++) // 현재 노드와 연결된 모든 노드 확인
	{
		int next = a[node][i]; // 다음 확인할 노드
		if (!check[next]) // 다음 노드가 방문하지 않은 노드라면
		{
			dfs(next); // 다음 노드 탐색
		}
	}
}

void bfs(int start)
{
	queue<int> q;	// 큐 선언

	check[start] = true; // 첫 노드 방문처리
	q.push(start); // 시작 노드 큐에 삽입

	while (!q.empty()) // 큐가 비어있지 않으면 반복
	{
		int node = q.front(); // 큐의 맨 앞 원소 저장
		q.pop(); // 큐에서 하나의 노드를 꺼냄
		
		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (check[next] == false) // 방문하지 않은 노드라면
			{
				check[next] = true; // 방문 처리
				q.push(next); // 큐에 push
			}
		}
	}

}

int main(void)
{
	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int cnt = 0; // 연결요소의 개수

	for (int i = 1; i <= n; i++) // 모든 노드를 확인
	{
		if (!check[i]) // 방문하지 않은 노드이면 탐색
		{		// 이미 방문했던 노드는 어떤 하나의 연결 요소에 포함되었을 것임
			bfs(i);
			cnt++;
		}
	}
		
	cout << cnt << '\n';
}