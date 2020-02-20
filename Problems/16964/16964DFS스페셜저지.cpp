#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<int> a[100001];
bool check[100001];
vector<int> dfs_order;


void dfs(int node, vector<int>& d)
{
	check[node] = true;
	dfs_order.push_back(node); // Ȯ���� ������ ������ ���� ���ĵ� ���� ����Ʈ�� dfs�� ������ ����� ��´�.
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (check[next] == false)
			dfs(next, d);
	}
}

int main(void)
{
	int n; // ������ ����
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--; // ������ 0���� �����ϵ��� ����(�ε����� 0���� �����ϹǷ�)
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> d(n);
	vector<int> order(n);
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
		d[i]--; // ������ 0���� ����
		order[d[i]] = i; // Ȯ���� ������ ������ ������ ����
	}

	for (int i = 0; i < n; i++)
		sort(a[i].begin(), a[i].end(), [&](int a, int b)
			{
				return order[a] < order[b]; // ���� ����Ʈ�� Ȯ���� ������ ������ ���� ����
			});
	
	dfs(0, d);

	if (d == dfs_order)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}