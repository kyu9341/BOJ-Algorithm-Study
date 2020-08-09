#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int MAX = 50 + 1;
int r, c;
char a[MAX][MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool check[MAX][MAX];
queue<pair<int, int>> wq; // 물의 이동을 담을 큐
int water[MAX][MAX]; // 물의 이동 시간
int ans = 0;

struct location {
	int x;
	int y;
	int time;
};

void waterFlow() { // 물의 이동을 기록하는 함수

	while (!wq.empty()) {
		int x = wq.front().first;
		int y = wq.front().second;
		wq.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
				if (a[nx][ny] == '.' && water[nx][ny] == -1) {
					water[nx][ny] = water[x][y] + 1;
					wq.push(make_pair(nx, ny));
				}
			}
		}	
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;
	location start;
	memset(water, -1, sizeof(water));
	int ex, ey;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') { // 처음 고슴도치의 위치
				start.x = i;
				start.y = j;
				start.time = 0;
				check[i][j] = true;
			}
			if (a[i][j] == '*') { // 물의 시작 위치
				wq.push(make_pair(i, j));
				water[i][j] = 0;
			}
			if (a[i][j] == 'D') { // 목적지 위치
				ex = i;
				ey = j;
			}
		}
	}
	waterFlow();

	queue<location> q;
	q.push(start);

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int time = q.front().time;
		q.pop();
		
		if (a[x][y] == 'D') { // 비버의 굴에 도착했을 때
			ans = time; // 시간 기록 후 종료
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = time + 1;
			if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
				// 방문하지 않았고, 빈 지역 또는 비버의 굴이며, 물이 다음에도 차오르지 않는 지역인 경우
				if (!check[nx][ny] && (a[nx][ny] == '.' || a[nx][ny] == 'D') && (nt < water[nx][ny] || water[nx][ny] == -1)) {
					q.push(location{ nx, ny, nt });
					check[nx][ny] = true;
				}
			}

		}
	}

	if (!check[ex][ey]) {
		cout << "KAKTUS" << '\n';
		return 0;
	}
	cout << ans << '\n';
}