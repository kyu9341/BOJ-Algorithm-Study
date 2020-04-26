#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int MAX = 1000;
int a[MAX][MAX];
int dist[MAX][MAX][2];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, m;

int bfs() {

	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 0 });
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int check = q.front().second; // 벽을 부쉈는지 여부

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				// 중복이 아닌 경우만 확인
				if (dist[nx][ny][check] == -1) {
					if (a[nx][ny] == 0) { // 다음 위치가 이동 가능하다면 그냥 이동
						q.push({ { nx, ny }, check }); 
						dist[nx][ny][check] = dist[x][y][check] + 1;
					}
					else if(a[nx][ny] == 1 && check == 0){ // 다음 위치가 벽인데 아직 부수지 않았다면
						q.push({ {nx, ny}, 1 }); // 벽을 부수고 이동하는 경우 추가
						dist[nx][ny][1] = dist[x][y][0] + 1;
					}
				}
			}
		}
		// 벽을 부수는 경우와 부수지 않는 경우 모두 도착할 수 있다면 더작은 값 리턴
		if (dist[n - 1][m - 1][0] != -1 && dist[n - 1][m - 1][1] != -1) {
			return min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
		}
	}
	// 둘다 도착하지 못했다면 -1, 하나만 도착했다면 그 거리를 리턴
	return max(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	vector<pair<int, int>> wall;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			a[i][j] = input[j] - '0';
		}
	}
	memset(dist, -1, sizeof(dist));

	cout << bfs() << '\n';
	
}