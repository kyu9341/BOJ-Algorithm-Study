#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
vector<int> a[3001];
int dist[3001];
int check[3001]; // 0 : �湮 x , 1 : �湮, 2 : ����Ŭ

int dfs(int node, int p) // p : ���� ���
{	// -2 : ����Ŭ�� ã������ ����Ŭ�� ���Ե��� �ʴ� ���
	// -1 : ����Ŭ�� ã�� ���� ���
	// 0 ~ n - 1 : ����Ŭ�� ã�� ��� (����Ŭ�� ���� �ε���)

	if (check[node] == 1) return node; // ó������ �湮�ߴ� ��带 �ٽ� �����ٸ� ����Ŭ�� ������
	check[node] = 1; // �湮 ó��
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (next != p) // ���� ���δ� ���� ����
		{
			int res = dfs(next, node);
			if (res == -2) return -2;
			if (res >= 0) // ����Ŭ�� ã�� ���(����Ŭ ���� ���)
			{
				check[node] = 2; // ����Ŭ�� ����
				if (node == res) return -2; // ����Ŭ�� �������� ã�Ҵٸ� ������� ����Ŭ�� �ƴ�
				else return res; // ����Ŭ ���� ��带 ����
			}
		}
	}
	return -1; // ����Ŭ�� ã�� ����
}

int main(void)
{
	int n; // ���� ����
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	dfs(1, -1); // dfs�� ����Ŭ�� ���Կ��θ� ��� ����
	
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 2) // ����Ŭ�� ���Ե� ���
		{
			dist[i] = 0; // ����Ŭ���� �Ÿ��� 0
			q.push(i);
		}
		else
		{
			dist[i] = -1;
		}
	}

	while (!q.empty()) // bfs�� ����Ŭ���� �Ÿ��� ����
	{ 
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (dist[next] == -1) // ���� ��尡 ����Ŭ�� ���ԵǾ����� �ʴٸ�
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