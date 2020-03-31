#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 100000;
int n, m;
vector<int> v[MAX + 1];
int cost[MAX + 1]; // ���� Ƚ��

void go(int now)
{
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		cost[next] += cost[now]; // ���� ��ġ ����
		go(next);
	}
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		if (i == 1) continue; // -1�� �ǳʶ�
		v[k].push_back(i);
	}
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		cost[u] += v;// ���� ���� ����
	}
	go(1); // 1������ dfs
	for (int i = 1; i <= n; i++)
		cout << cost[i] << ' ';
	cout << '\n';

}