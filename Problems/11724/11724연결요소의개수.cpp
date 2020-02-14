#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int node)
{
	check[node] = true; // �湮 ó��

	for (int i = 0; i < a[node].size(); i++) // ���� ���� ����� ��� ��� Ȯ��
	{
		int next = a[node][i]; // ���� Ȯ���� ���
		if (!check[next]) // ���� ��尡 �湮���� ���� �����
		{
			dfs(next); // ���� ��� Ž��
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
	int cnt = 0; // �������� ����

	for (int i = 1; i <= n; i++) // ��� ��带 Ȯ��
	{
		if (!check[i]) // �湮���� ���� ����̸� Ž��
		{		// �̹� �湮�ߴ� ���� � �ϳ��� ���� ��ҿ� ���ԵǾ��� ����
			dfs(i);
			cnt++;
		}
	}
		
	cout << cnt << '\n';
}