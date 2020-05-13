# Problem 1753

## 최단경로

### 문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

### 입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

### 출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

### 문제 링크
<https://www.acmicpc.net/problem/1753>

### 예제 입력 1
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

### 예제 출력 1
0
2
3
7
INF

### solve
- 다익스트라 알고리즘을 이용하여 해결하였다.
- 다익스트라 알고리즘 동작 방식
1. 출발 노드를 설정한다.
2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장한다.
3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택한다.
4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신한다.
5. 위 과정에서 3번 ~ 4번을 반복한다.
---
- 거리를 기준으로 최소 힙의 구조로 동작하는 우선순위 큐를 선언한다.
- 현제 노드에서 가까운 순서대로 큐에서 꺼내어 더 짧은 거리일 경우에만 dist의 값을 갱신한다.

### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<climits>
#include<cmath>

using namespace std;
const int MAX = 20001;
const int INF = INT_MAX;

vector<pair<int, int>> a[MAX];
int dist[MAX];

void dijkstar(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소 힙 구조로 선언
	pq.push(make_pair(0, start)); // 앞의 값을 기준으로 최소 힙 구성

	// 가까운 순서대로 처리하므로 큐를 사용
	while (!pq.empty()) {
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();
		// 최단 거리가 아닌 경우 스킵
		if (dist[current] < cost) continue;
		for (int i = 0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드
			int next = a[current][i].first;
			// 선택된 노드를 거쳐서 인접 노드로 가는 비용
			int nextCost = cost + a[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체한다.
			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push(make_pair(nextCost, next));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v, e;
	cin >> v >> e;
	int start;
	cin >> start;

	fill(dist, &dist[v + 1], INF);


	while (e--) {
		int x, y, w;
		cin >> x >> y >> w;
		a[x].push_back(make_pair(y, w));
	}

	dijkstar(start);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}

}
```
