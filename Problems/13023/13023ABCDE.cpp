#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring> // memset

using namespace std;
vector<int> a[2001]; // ���� ����Ʈ
bool check[2001];
bool ans = false;

void dfs(int node, int count)
{
	if (count == 5) // 5���� �������� ģ���� ���
	{
		ans = true;
		return;
	}
	check[node] = true; // ���� ��� �湮 ó��
	for (int i = 0; i < a[node].size(); i++) // ���� ���� ����� ��� Ȯ��
	{
		int next = a[node][i]; // ���� Ȯ���� ���
		if (!check[next]) // �湮���� �ʾҴٸ�
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
		memset(check, false, sizeof(check)); // check�迭 �ʱ�ȭ
		dfs(i, 1); // count = 1 ���� ����
		if (ans) // count�� 5�� ���
		{
			cout << 1 << '\n';
			break;
		}
	}
	if (!ans)
		cout << 0 << '\n';

}