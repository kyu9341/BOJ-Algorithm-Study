# Problem 1707

## 이분 그래프

### 문제
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

### 입력
입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K(2≤K≤5)가 주어진다. 각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)가 빈 칸을 사이에 두고 순서대로 주어진다. 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호가 빈 칸을 사이에 두고 주어진다.

### 출력
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1707>

### 예제 입력 1
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2

### 예제 출력 1
YES
NO

### solve
- 그래프를 다음과 같이 A와 B로 나눌 수 있으면 **이분 그래프** 라고 한다.

![bipartite_graph](https://github.com/kyu9341/BOJ-Algorithm-Study/blob/master/pictures/bipartite_graph.png)

- A에 포함된 정점끼리 연결된 간선이 없음
- B에 포함된 정점끼리 연결된 간선이 없음
- 모든 간선의 한 끝 점은 A에, 다른 끝 점은 B에
---

- check배열을 bool타입 대신 int형으로 선언하여 방문하지 않은 노드는 0, 방문한 노드인데 1번 그룹이라면 1, 2번 그룹이라면 2로 저장한다.
	- (dfs or bfs)를 통해 탐색을 수행하며 다음 노드로 넘어가면 그룹을 바꿔서 지정해준다. 이때 다음에 방문한 노드가 같은 그룹에 속한 노드라면 이분 그래프가 아니다.
- (dfs or bfs)에서 다음 노드가 방문하지 않은 노드라면 다음 노드로 재귀 호출하며 현재 1번 그룹이라면 다음은 2번을 넘겨주고 현재 2번이라면 1번을 넘겨준다.
- 다음 노드가 방문을 했던 노드인데 현재 노드와 같은 그룹이라면 이분 그래프가 아니다.

- 각 테스트케이스를 시작할 때마다 인접 노드와 방문 내역을 초기화 해야한다.

### 코드 설명
```C++
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
```
