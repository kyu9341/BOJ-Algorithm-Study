#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
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