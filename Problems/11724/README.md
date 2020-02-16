# Problem 11724

## 연결 요소의 개수

### 문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

### 출력
첫째 줄에 연결 요소의 개수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/11724>

### 예제 입력 1
6 5
1 2
2 5
5 1
3 4
4 6

### 예제 출력 1
2

### 예제 입력 2
6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3

### 예제 출력 2
1

### solve
- 연결 요소란, 하나의 노드에 대해 간선으로 연결된 모든 노드의 집합이다.
- 연결 요소의 개수를 구하기 위해 인접 리스트를 입력 받고 dfs또는 bfs를 이용하여 모든 노드를 확인한다.
	- 이때 이전에 방문했던 노드라면 이미 다른 연결 요소에 포함되었다는 뜻이므로 방문하지 않은 노드라면 탐색을 수행하고 연결 요소의 개수를 1증가시킨다.


### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int node)
{
	check[node] = true; // 방문 처리

	for (int i = 0; i < a[node].size(); i++) // 현재 노드와 연결된 모든 노드 확인
	{
		int next = a[node][i]; // 다음 확인할 노드
		if (!check[next]) // 다음 노드가 방문하지 않은 노드라면
		{
			dfs(next); // 다음 노드 탐색
		}
	}
}

void bfs(int start)
{
	queue<int> q;	// 큐 선언

	check[start] = true; // 첫 노드 방문처리
	q.push(start); // 시작 노드 큐에 삽입

	while (!q.empty()) // 큐가 비어있지 않으면 반복
	{
		int node = q.front(); // 큐의 맨 앞 원소 저장
		q.pop(); // 큐에서 하나의 노드를 꺼냄

		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (check[next] == false) // 방문하지 않은 노드라면
			{
				check[next] = true; // 방문 처리
				q.push(next); // 큐에 push
			}
		}
	}

}

int main(void)
{
	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int cnt = 0; // 연결요소의 개수

	for (int i = 1; i <= n; i++) // 모든 노드를 확인
	{
		if (!check[i]) // 방문하지 않은 노드이면 탐색
		{		// 이미 방문했던 노드는 어떤 하나의 연결 요소에 포함되었을 것임
			bfs(i);
			cnt++;
		}
	}

	cout << cnt << '\n';
}
```
