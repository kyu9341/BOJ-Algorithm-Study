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

	memset(dist, -1, sizeof(dist)); // �ֻ��� Ƚ���� ��� -1�� �ʱ�ȭ

	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u] =  v; // ��ٸ�
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u] = v; // ��
	}

	queue<int> q;
	q.push(1); // 1���� ����
	dist[1] = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		if (dist[100] != -1) break; // 100�� �湮�ߴٸ� break

		for (int i = 1; i <= 6; i++) // ������ �ֻ��� �� (1~6)
		{
			int next = node + i; // ���� ���
			if (a[next] != 0) next = a[next]; // ���� ��尡 �� �Ǵ� ��ٸ��� ����Ǿ� �ִٸ� ��� �̵�(�ݵ�� �̵��ؾ���)
			if (dist[next] == -1 && node + i <= 100) // ���� ������ ���� �湮���� ���� ���
			{
				q.push(next);
				dist[next] = dist[node] + 1; // �ֻ��� Ƚ�� �߰�
			}

		}
	}
	cout << dist[100] << '\n';
}