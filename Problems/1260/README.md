# Problem 1260

## DFS와 BFS

### 문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

### 입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

### 출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

### 문제 링크
<https://www.acmicpc.net/problem/1260>

### 예제 입력 1
4 5 1
1 2
1 3
1 4
2 4
3 4

### 예제 출력 1
1 2 4 3
1 2 3 4

### 예제 입력 2
5 5 3
5 4
5 2
1 2
3 4
3 1

### 예제 출력 2
3 1 2 5 4
3 1 4 2 5

### 예제 입력 3
1000 1 1000
999 1000

### 예제 출력 3
1000 999
1000 999

### solve
- 깊이 우선 탐색(DFS) : 재귀 함수를 통해 구현
- 너비 우선 탐색(BFS) : 큐로 구현
- https://kyu9341.github.io/algorithm/2020/01/03/algorithmBFS/
- https://kyu9341.github.io/algorithm/2020/01/03/algorithmDFS/

### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

bool check[1001];
vector<int> a[1001];

void dfs(int node)
{
	check[node] = true; // 현재 노드 방문 처리
	cout << node << ' ';
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i]; // 다음에 방문할 노드 번호를 저장
		if (!check[next]) // 다음 노드가 방문하지 않았다면
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	memset(check, false, sizeof(check)); // 메모리 초기화
	check[start] = true;
	q.push(start); // 큐에 시작 노드 push
	while (!q.empty()) // 큐가 비어있지 않으면 반복
	{
		int node = q.front(); // 큐의 맨 앞 원소
		q.pop(); // 큐에서 제거
		cout << node << ' '; // 출력
		for (int i = 0; i < a[node].size(); i++) // 현재 노드와 연결된 노드를 확인
		{
			int next = a[node][i];
			if (!check[next]) // 방문하지 않은 노드면
			{
				check[next] = true; // 방문 처리 후
				q.push(next); // 큐에 push
			}
		}
	}
}

int main(void)
{
	int n, m, start;
	cin >> n >> m >> start;

	while (m--)
	{
		int u, v; // 연결되는 두 정점
		cin >> u >> v;

		a[u].push_back(v); // 두 정점을 연결시킨다
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end()); // 각 인접 리스트를 정렬

	dfs(start);
	cout << '\n';
	bfs(start);
	cout << '\n';
}
```
