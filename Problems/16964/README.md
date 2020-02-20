# Problem 16964

## DFS 스페셜 저지

### 문제
BOJ에서 정답이 여러가지인 경우에는 스페셜 저지를 사용한다. 스페셜 저지는 유저가 출력한 답을 검증하는 코드를 통해서 정답 유무를 결정하는 방식이다. 오늘은 스페셜 저지 코드를 하나 만들어보려고 한다.

정점의 개수가 N이고, 정점에 1부터 N까지 번호가 매겨져있는 양방향 그래프가 있을 때, DFS 알고리즘은 다음과 같은 형태로 이루어져 있다.

```cpp
void dfs(int x) {
    if (check[x] == true) {
        return;
    }
    check[x] = true;
    // x를 방문
    for (int y : x와 인접한 정점) {
        if (check[y] == false) {
            dfs(y);
        }
    }
}
```

이 문제에서 시작 정점은 1이기 때문에 가장 처음에 호출하는 함수는 dfs(1)이다. DFS 방문 순서는 dfs함수에서 // x를 방문 이라고 적힌 곳에 도착한 정점 번호를 순서대로 나열한 것이다.

트리가 주어졌을 때, 올바른 DFS 방문 순서인지 구해보자.

### 입력
첫째 줄에 정점의 수 N(2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에는 트리의 간선 정보가 주어진다. 마지막 줄에는 DFS 방문 순서가 주어진다. DFS 방문 순서는 항상 N개의 정수로 이루어져 있으며, 1부터 N까지 자연수가 한 번씩 등장한다.

### 출력
입력으로 주어진 DFS 방문 순서가 올바른 순서면 1, 아니면 0을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/16964>

### 예제 입력 1
4
1 2
1 3
2 4
1 2 3 4

### 예제 출력 1
0

### 예제 입력 2
4
1 2
1 3
2 4
1 2 4 3

### 예제 출력 2
1

### 예제 입력 3
4
1 2
1 3
2 4
1 3 2 4

### 예제 출력 3
1

### solve
- 입력된 방문 순서가 올바른 dfs의 순서인지 판별하는 문제이다.
- 입력된 방문 순서에 따라 각 노드의 인접 리스트를 정렬한 후 dfs를 수행하였을때
	- 입력된 방문 순서와 같은 순서가 나온다면 올바른 순서이고 아니라면 잘못된 순서이다.
- 입력된 방문 순서를 저장할 벡터 d와 입력받은 방문 순서대로 인덱스를 저장할 벡터 order을 만든다.
	- order[d[i]] = i 와 같이 입력된 노드 순서대로 인덱스를 저장한다.
	- 각 노드의 인접 리스트가 저장된 벡터 a를 모두 order에 저장된 순서로 정렬한다.
- 이후 그 순서로 bfs를 수행한 결과를 dfs_order라는 벡터에 담고 b와 비교하여 같으면 1, 다르면 0을 출력한다.



### 코드 설명
```C++
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

```
