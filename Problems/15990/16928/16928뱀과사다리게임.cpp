#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
int a[101];
int dist[101];

int main(void)
{
	int n, m;
	cin >> n >> m;

	memset(dist, -1, sizeof(dist)); // 주사위 횟수를 모두 -1로 초기화

	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u] =  v; // 사다리
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u] = v; // 뱀
	}

	queue<int> q;
	q.push(1); // 1부터 시작
	dist[1] = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		if (dist[100] != -1) break; // 100을 방문했다면 break

		for (int i = 1; i <= 6; i++) // 가능한 주사위 눈 (1~6)
		{
			int next = node + i; // 다음 노드
			if (a[next] != 0) next = a[next]; // 다음 노드가 뱀 또는 사다리에 연결되어 있다면 즉시 이동(반드시 이동해야함)
			if (dist[next] == -1 && node + i <= 100) // 범위 내에서 아직 방문하지 않은 경우
			{
				q.push(next);
				dist[next] = dist[node] + 1; // 주사위 횟수 추가
			}

		}
	}
	cout << dist[100] << '\n';
}