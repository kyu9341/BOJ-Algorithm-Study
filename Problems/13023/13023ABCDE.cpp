#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring> // memset

using namespace std;
vector<int> a[2001]; // 인접 리스트
bool check[2001];
bool ans = false;

void dfs(int node, int count)
{
	if (count == 5) // 5명이 연속으로 친구인 경우
	{
		ans = true;
		return;
	}
	check[node] = true; // 현재 노드 방문 처리
	for (int i = 0; i < a[node].size(); i++) // 현재 노드와 연결된 노드 확인
	{
		int next = a[node][i]; // 다음 확인할 노드
		if (!check[next]) // 방문하지 않았다면
		{
			dfs(next, count + 1);
		}
		if (ans) return;
	}
	check[node] = false;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i <= n; i++)
		sort(a[i].begin(), a[i].end());
	
	for (int i = 0; i <= n; i++)
	{
		ans = false;
		memset(check, false, sizeof(check)); // check배열 초기화
		dfs(i, 1); // count = 1 부터 시작
		if (ans) // count가 5인 경우
		{
			cout << 1 << '\n';
			break;
		}
	}
	if (!ans)
		cout << 0 << '\n';

}