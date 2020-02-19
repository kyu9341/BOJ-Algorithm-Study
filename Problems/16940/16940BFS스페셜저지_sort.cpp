#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<int> a[100001];
bool check[100001];
int n; // 정점의 개수
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

	vector<int> b(n + 1); // 이 벡터에 입력된 순서가 맞는지 확인해야함
	vector<int> order(n + 1); // 인접리스트를 정렬하기 위한 기준 벡터(확인할 벡터의 순서)

	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		order[b[i]] = i; // 입력을 받은 순서대로 인덱스를 저장할 벡터
	}

	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end(), [&](const int& u, const int& v)
			{
				return order[u] < order[v];
			}); // 인접 리스트를 확인할 벡터의 순서로 정렬한다.
	}

	vector<int> bfs_order; // bfs가 맞는지 검사할 배열의 순서로 정렬된 a로 실제 bfs를 수행한 순서를 저장할 벡터
	bfs_order.push_back(0); // b와 비교하기 위해(b는 1부터 시작되므로)
	queue<int> q;
	q.push(1);
	check[1] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		bfs_order.push_back(node); // pop할때 출력

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
	
	if (bfs_order == b) // 확인할 벡터와 그 순서로 정렬된 인접리스트로 bfs를 수행한 벡터를 비교
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

}