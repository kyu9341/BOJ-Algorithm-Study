#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
const int MAX = 100000;
vector<int> a[MAX + 1];
bool check[MAX + 1];
int parent[MAX + 1];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) // ����� ������ n�� �� Ʈ���� ������ ������ n - 1��
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	queue<int> q;
	q.push(1); // ��Ʈ�� 1�̶�� �������Ƿ� 1���� Ž�� ����
	check[1] = true;

	while (!q.empty()) // bfsŽ��
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < a[node].size(); i++) // �� ����� ��� ���� ��� Ž��
		{
			int next = a[node][i];
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				parent[next] = node; // �θ� ��� ����
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}
	
}