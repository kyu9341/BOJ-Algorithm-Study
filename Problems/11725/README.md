# Problem 11725

## 트리의 부모 찾기

### 문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

### 출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/11725>

### 예제 입력 1
7
1 6
6 3
3 5
4 1
2 4
4 7

### 예제 출력 1
4
6
1
3
1
4

### 예제 입력 2
12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12

### 예제 출력 2
1
1
2
3
3
4
4
5
5
6
6

### solve
- 트리의 부모를 구하는 문제이다.
- 트리의 루트를 1이라고 정해놨으므로 bfs탐색을 통해 시작점을 1로 지정한 후 탐색을 하면 된다.
- bfs를 수행하며 다음 노드의 부모는 현재 노드이기 때문에 parent[next] = node 와 같이 기록한다.
- 탐색 후 2번 노드부터 출력한다.


### 코드 설명
```C++
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

	for (int i = 0; i < n - 1; i++) // 노드의 개수가 n일 때 트리의 간선의 개수는 n - 1개
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	queue<int> q;
	q.push(1); // 루트가 1이라고 정했으므로 1부터 탐색 시작
	check[1] = true;

	while (!q.empty()) // bfs탐색
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < a[node].size(); i++) // 각 노드의 모든 인접 노드 탐색
		{
			int next = a[node][i];
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				parent[next] = node; // 부모 노드 지정
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}

}

```
