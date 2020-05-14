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
const int MAX = 1001;
int dist[MAX];
vector<pair<int, int>> a[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start)); 
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first; // ��� (�ִ� ���� �ּ� ��ó�� ����ϱ� ���� ������ ����� ���� ����� �ٲپ� ������)
		int node = pq.top().second; // ���� ���
		pq.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i].first;
			int nextCost = a[node][i].second + cost;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push(make_pair(-nextCost, next)); // ��� (�ִ� ���� �ּ� ��ó�� ����ϱ� ���� ������ ����)
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