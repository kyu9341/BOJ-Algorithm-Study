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
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // �ּ� �� ������ ����
	pq.push(make_pair(0, start)); // ���� ���� �������� �ּ� �� ����

	// ����� ������� ó���ϹǷ� ť�� ���
	while (!pq.empty()) {
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();
		// �ִ� �Ÿ��� �ƴ� ��� ��ŵ
		if (dist[current] < cost) continue;
		for (int i = 0; i < a[current].size(); i++) {
			// ���õ� ����� ���� ���
			int next = a[current][i].first;
			// ���õ� ��带 ���ļ� ���� ���� ���� ���
			int nextCost = cost + a[current][i].second;
			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü�Ѵ�.
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