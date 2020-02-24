# Problem 1167

## 트리의 지름

### 문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

### 입력
트리가 입력으로 주어진다. 먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2≤V≤100,000)둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. (정점 번호는 1부터 V까지 매겨져 있다고 생각한다)

먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다. 주어지는 거리는 모두 10,000 이하의 자연수이다.

### 출력
첫째 줄에 트리의 지름을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1167>

### 예제 입력 1
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1

### 예제 출력 1
11

### solve
- 트리의 지름를 구하는 문제이다.
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

	for (int i = 1; i <= n; i++)
	{
		int k; // 현재 정점
		cin >> k;
		while (true)
		{
			int l, m;
			cin >> l;
			if (l == -1) break; // -1이면 다음 노드로
			cin >> m;
			a[k].push_back(make_pair(l, m)); // k와 연결된 노드와 거리 저장
		}
	}

	pair<int, int> tmp = bfs(1); // 어느 한 지점부터 가장 먼 노드를 구함
	pair<int, int> res = bfs(tmp.first); // 그 노드부터 다시 가장 먼 노드까지의 거리가 정답

	cout << res.second << '\n';

}

```
