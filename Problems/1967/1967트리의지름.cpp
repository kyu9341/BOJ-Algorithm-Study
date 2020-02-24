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
int n; // ������ ����

pair<int, int> bfs(int start)
{
	memset(dist, 0, sizeof(dist));
	memset(check, false, sizeof(check));

	queue<int> q;
	q.push(start);
	check[start] = true;
	dist[start] = 0; // ���� ����� �Ÿ��� 0

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
				dist[next] = dist[node] + ndist; // ���������� �Ÿ��� ����
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
	return { index, max }; // ���� �� �Ÿ��� �� �ε����� ����
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v, d; // d : �Ÿ�
		cin >> u >> v >> d;
		a[u].push_back(make_pair(v, d));
		a[v].push_back(make_pair(u, d));
	}

	pair<int, int> tmp = bfs(1); // ��� �� �������� ���� �� ��带 ����
	pair<int, int> res = bfs(tmp.first); // �� ������ �ٽ� ���� �� �������� �Ÿ��� ����

	cout << res.second << '\n';

}