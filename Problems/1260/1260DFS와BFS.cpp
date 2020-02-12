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
	check[node] = true; // ���� ��� �湮 ó��
	cout << node << ' ';
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i]; // ������ �湮�� ��� ��ȣ�� ����
		if (!check[next]) // ���� ��尡 �湮���� �ʾҴٸ�
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	memset(check, false, sizeof(check)); // �޸� �ʱ�ȭ
	check[start] = true;
	q.push(start); // ť�� ���� ��� push
	while (!q.empty()) // ť�� ������� ������ �ݺ�
	{
		int node = q.front(); // ť�� �� �� ����
		q.pop(); // ť���� ����
		cout << node << ' '; // ���
		for (int i = 0; i < a[node].size(); i++) // ���� ���� ����� ��带 Ȯ��
		{
			int next = a[node][i];
			if (!check[next]) // �湮���� ���� ����
			{
				check[next] = true; // �湮 ó�� ��
				q.push(next); // ť�� push
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
		int u, v; // ����Ǵ� �� ����
		cin >> u >> v;

		a[u].push_back(v); // �� ������ �����Ų��
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		sort(a[i].begin(), a[i].end()); // �� ���� ����Ʈ�� ����

	dfs(start);
	cout << '\n';
	bfs(start);
	cout << '\n';
}