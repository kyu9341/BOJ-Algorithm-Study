#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<int> a[100001];
bool check[100001];
int n; // ������ ����
int parent[100001];

int main(void)
{
	cin >> n;
	
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> b(n + 1); // �� ���Ϳ� �Էµ� ������ �´��� Ȯ���ؾ���
	vector<int> order(n + 1); // ��������Ʈ�� �����ϱ� ���� ���� ����(Ȯ���� ������ ����)

	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		order[b[i]] = i; // �Է��� ���� ������� �ε����� ������ ����
	}

	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end(), [&](const int& u, const int& v)
			{
				return order[u] < order[v];
			}); // ���� ����Ʈ�� Ȯ���� ������ ������ �����Ѵ�.
	}

	vector<int> bfs_order; // bfs�� �´��� �˻��� �迭�� ������ ���ĵ� a�� ���� bfs�� ������ ������ ������ ����
	bfs_order.push_back(0); // b�� ���ϱ� ����(b�� 1���� ���۵ǹǷ�)
	queue<int> q;
	q.push(1);
	check[1] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		bfs_order.push_back(node); // pop�Ҷ� ���

		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
			}
		}
	}
	
	if (bfs_order == b) // Ȯ���� ���Ϳ� �� ������ ���ĵ� ��������Ʈ�� bfs�� ������ ���͸� ��
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

}