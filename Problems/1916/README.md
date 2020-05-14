# Problem 1916

## 최소비용 구하기

### 문제
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.

### 입력
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.

그리고 M+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다. 출발점에서 도착점을 갈 수 있는 경우만 입력으로 주어진다.

### 출력
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1916>

### 예제 입력 1
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

### 예제 출력 1
4

### solve
- 다익스트라 알고리즘을 이용하여 해결하였다.
- 다익스트라 알고리즘 동작 방식
1. 출발 노드를 설정한다.
2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장한다.
3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택한다.
4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신한다.
5. 위 과정에서 3번 ~ 4번을 반복한다.
---
- 거리를 기준으로 최소 힙의 구조로 동작하는 우선순위 큐로 사용하기 위해 최대 힙에 비용 값을 음수로 변환하여 저장한다.
- 현제 노드에서 가까운 순서대로 큐에서 꺼내어 더 짧은 거리일 경우에만 dist의 값을 갱신한다.
	- 큐에서 꺼낼 때는 음수를 양수로 바꾸어주고 넣을 때는 양수를 음수로 바꾸어 넣어준다.

### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<climits>
#include<cmath>

using namespace std;
const int MAX = 1001;
int dist[MAX];
vector<pair<int, int>> a[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first; // 비용 (최대 힙을 최소 힙처럼 사용하기 위해 음수로 저장된 수를 양수로 바꾸어 가져옴)
		int node = pq.top().second; // 현재 노드
		pq.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i].first;
			int nextCost = a[node][i].second + cost;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push(make_pair(-nextCost, next)); // 비용 (최대 힙을 최소 힙처럼 사용하기 위해 음수로 저장)
			}

		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	int start, end;

	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
	}
	cin >> start >> end;
	fill(dist, &dist[n + 1], INT_MAX);

	dijkstra(start);

	cout << dist[end] << '\n';

}
```
