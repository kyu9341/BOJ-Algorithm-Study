#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;
const int MAX = 10000;
vector<pair<int, int>> a[MAX + 1];
bool check[MAX + 1]; // �湮 ����

bool dfs(int node, int weight, int target) // dfs�� ���� ���� �߷� ������ �����ϴ� ���� �ִ��� Ȯ��
{
	check[node] = true; // �湮 ó��
	if (check[target]) return true;

	for (int i = 0; i < a[node].size(); i++) // ����� �� ��� Ȯ��
	{
		int next = a[node][i].first;
		int w = a[node][i].second;
		if (!check[next] && w >= weight) // �߷� ������ �����ϰ� �湮���� ���� ���
		{
			if (dfs(next, weight, target)) return true; // ��ǥ ������ ã�Ҵٸ� true����
		}
	}
	return false; // ��� �湮������ ��ǥ ������ ã�� ���� ��� false
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	int maxWeight = 0;
	for (int i = 0; i < m; i++) // ���� �ٸ� �Է�
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
		a[v].push_back(make_pair(u, w));
		if (maxWeight < w) // �߷� ������ �ִ� ����
			maxWeight = w;
	}
	int start, end; // ��� ����, ���� ����
	cin >> start >> end;

	int left = 1;
	int right = maxWeight;
	int ans = 0;

	while (left <= right) // �̺� Ž��
	{
		memset(check, false, sizeof(check)); // check�迭 �ʱ�ȭ
		int mid = (left + right) / 2; // �߷� ����
		if (dfs(start, mid, end)) // ���� �߷� ������ �����ϴ� ���� �ִ� ���
		{
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans << '\n';

}