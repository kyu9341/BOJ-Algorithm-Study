# Problem 1967

## 트리의 지름

### 문제
트리(tree)는 사이클이 없는 무방향 그래프이다. 트리에서는 어떤 두 노드를 선택해도 둘 사이에 경로가 항상 하나만 존재하게 된다. 트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 가장 길게 늘어나는 경우가 있을 것이다. 이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.

이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다. 정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.

입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을 구해서 출력하는 프로그램을 작성하시오. 아래와 같은 트리가 주어진다면 트리의 지름은 45가 된다.

### 입력
파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 둘째 줄부터 n번째 줄까지 각 간선에 대한 정보가 들어온다. 간선에 대한 정보는 세 개의 정수로 이루어져 있다. 첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고, 두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다. 간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.

### 출력
첫째 줄에 트리의 지름을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1967>

### 예제 입력 1
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
### 예제 출력 1
45

### solve
- 트리의 지름를 구하는 문제이다. 1167번 트리의 지름 문제와 똑같다고 할 수 있다.
	- 입력 방식만 바꿔서 풀었다.
- 트리에 존재하는 모든 경로 중에서 가장 긴 것의 길이를 트리의 지름이라 한다.
- 트리의 지름은 탐색 2번으로 구할 수 있다.
	- 한 정점 s에서 모든 정점까지의 거리를 구한다. 이 때, 가장 먼 거리인 정점을 u라고 한다.
	- u에서 모든 정점까지의 거리를 구한다. 이 때, 가장 먼 거리인 정점 v를 구한다.
	- 이 때, u와 v사이의 거리가 트리의 지름이다.
- 인접 리스트를 저장할 벡터에 각 노드와 연결된 노드와 그 사이의 거리를 저장한다.
- bfs를 이용하여 임의의 한 정점에서 다른 모든 정점까지의 거리를 구하고 그 최댓값을 가지는 인덱스를 반환한다.
- 반환받은 정점에서 다시 bfs를 수행하여 가장 먼 노드까지의 거리를 구한다.


### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
const int MAX = 100000;
vector<pair<int, int>> a[MAX + 1];
bool check[MAX + 1];
int dist[MAX + 1];
int n; // 정점의 개수

pair<int, int> bfs(int start)
{
	memset(dist, 0, sizeof(dist));
	memset(check, false, sizeof(check));

	queue<int> q;
	q.push(start);
	check[start] = true;
	dist[start] = 0; // 시작 노드의 거리는 0

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i].first;
			int ndist = a[node][i].second;
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				dist[next] = dist[node] + ndist; // 시작점과의 거리를 저장
			}
		}
	}
	int max = 0;
	int index;
	for (int i = 1; i <= n; i++)
	{
		if (max < dist[i])
		{
			max = dist[i];
			index = i;
		}
	}
	return { index, max }; // 가장 먼 거리와 그 인덱스를 리턴
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v, d; // d : 거리
		cin >> u >> v >> d;
		a[u].push_back(make_pair(v, d));
		a[v].push_back(make_pair(u, d));
	}

	pair<int, int> tmp = bfs(1); // 어느 한 지점부터 가장 먼 노드를 구함
	pair<int, int> res = bfs(tmp.first); // 그 노드부터 다시 가장 먼 노드까지의 거리가 정답

	cout << res.second << '\n';

}

```
