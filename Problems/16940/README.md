# Problem 16940

## BFS 스페셜 저지

### 문제
BOJ에서 정답이 여러가지인 경우에는 스페셜 저지를 사용한다. 스페셜 저지는 유저가 출력한 답을 검증하는 코드를 통해서 정답 유무를 결정하는 방식이다. 오늘은 스페셜 저지 코드를 하나 만들어보려고 한다.

정점의 개수가 N이고, 정점에 1부터 N까지 번호가 매겨져있는 양방향 그래프가 있을 때, BFS 알고리즘은 다음과 같은 형태로 이루어져 있다.

큐에 시작 정점을 넣는다. 이 문제에서 시작 정점은 1이다. 1을 방문했다고 처리한다.
큐가 비어 있지 않은 동안 다음을 반복한다.
큐에 들어있는 첫 정점을 큐에서 꺼낸다. 이 정점을 x라고 하자.
x와 연결되어 있으면, 아직 방문하지 않은 정점 y를 모두 큐에 넣는다. 모든 y를 방문했다고 처리한다.
2-2 단계에서 방문하지 않은 정점을 방문하는 순서는 중요하지 않다. 따라서, BFS의 결과는 여러가지가 나올 수 있다.

트리가 주어졌을 때, 올바른 BFS 방문 순서인지 구해보자.

### 입력
첫째 줄에 정점의 수 N(2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에는 트리의 간선 정보가 주어진다. 마지막 줄에는 BFS 방문 순서가 주어진다. BFS 방문 순서의 항상 N개의 정수로 이루어져 있으며, 1부터 N까지 자연수가 한 번씩 등장한다.

### 출력
입력으로 주어진 BFS 방문 순서가 올바른 순서면 1, 아니면 0을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/16940>

### 예제 입력 1
4
1 2
1 3
2 4
1 2 3 4

### 예제 출력 1
1

### 예제 입력 2
4
1 2
1 3
2 4
1 2 4 3

### 예제 출력 2
0

### solve
- 입력된 방문 순서가 올바른 bfs의 순서인지 판별하는 문제이다.
- 입력된 방문 순서에 따라 각 노드의 인접 리스트를 정렬한 후 bfs를 수행하였을때
	- 입력된 방문 순서와 같은 순서가 나온다면 올바른 순서이고 아니라면 잘못된 순서이다.
- 입력된 방문 순서를 저장할 벡터 b와 입력받은 방문 순서대로 인덱스를 저장할 벡터 order을 만든다.
	- order[b[i]] = i 와 같이 입력된 노드 순서대로 인덱스를 저장한다.
	- 각 노드의 인접 리스트가 저장된 벡터 a를 모두 order에 저장된 순서로 정렬한다.
- 이후 그 순서로 bfs를 수행한 결과를 bfs_order라는 벡터에 담고 b와 비교하여 같으면 1, 다르면 0을 출력한다.



### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<int> a[100001];
bool check[100001];
int n; // 정점의 개수

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

```
