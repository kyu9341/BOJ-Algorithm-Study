#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
vector<int> a[20001];
int check[20001] = { 0 }; // 0 : 방문 x, 1 : 1번 그룹에 포함, 2 : 2번 그룹에 포함

bool dfs(int node, int c) // c : 다음 방문할 노드의 그룹 ( 1 or 2 ) , 이분그래프이면 true, 아니면 false
{
	check[node] = c; // c 그룹 방문 처리
	
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i]; // 다음 노드
		if (!check[next]) // 다음 정점을 방문 안했으면 동작
		{
			if (!dfs(next, 3 - c)) // 다음 노드는 현재 그룹이 1이라면 2, 2라면 1
				return false; // false를 리턴받았으면 false리턴
		}
		else if (check[next] == check[node]) // 다음 정점이 이미 방문했던 정점인데 현재 정점과 같은 그룹이면 이분그래프가 아님
			return false;
	}
	return true;
}

bool bfs(int start, int c)
{
	queue<int> q;
	check[start] = c; // 그룹 지정
	q.push(start); // 첫 노드 push

	while (!q.empty())
	{
		int node = q.front();
		q.pop(); 

		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (check[next] == 0)
			{
				c = 3 - check[node]; 
				check[next] = c; // 다음 노드는 현재 그룹이 1이라면 2, 2라면 1로 방문 처리
				q.push(next); // 방문처리하며 push
			}
			else if (check[node] == check[next])
			{
				return false;
			}
		}
	}
	return true;
}

int main(void)
{
	int k; // testcase
	cin >> k;

	while (k--)
	{
		int v, e;
		cin >> v >> e;

		for (int i = 1; i <= v; i++)
		{
			a[i].clear(); // 인접 노드 초기화
			check[i] = 0; // 방문 내역 초기화
		}

		for (int i = 0; i < e; i++)
		{
			int n, m;
			cin >> n >> m;
			a[n].push_back(m);
			a[m].push_back(n);
		}

		bool ok = true;
		for (int i = 1; i <= v; i++) // 모든 정점을 확인하여 이분 그래프가 아닌 경우가 있는지 확인
		{
			if (check[i] == 0) // 아직 방문 안한 노드에 대해서 확인
			{
				if (bfs(i, 1) == false) // dfs(i, 1) 도 가능
					ok = false;
			}
			
		}

		if (ok)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

}