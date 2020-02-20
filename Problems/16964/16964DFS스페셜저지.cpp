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
	dfs_order.push_back(node); // 확인할 벡터의 순서에 따라 정렬된 인접 리스트로 dfs를 수행한 결과를 담는다.
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (check[next] == false)
			dfs(next, d);
	}
}

int main(void)
{
	int n; // 정점의 개수
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--; // 정점을 0부터 시작하도록 지정(인덱스가 0부터 시작하므로)
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> d(n);
	vector<int> order(n);
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
		d[i]--; // 정점을 0부터 시작
		order[d[i]] = i; // 확인할 벡터의 순서를 저장할 벡터
	}

	for (int i = 0; i < n; i++)
		sort(a[i].begin(), a[i].end(), [&](int a, int b)
			{
				return order[a] < order[b]; // 인접 리스트를 확인할 벡터의 순서에 따라 정렬
			});
	
	dfs(0, d);

	if (d == dfs_order)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}