# Problem 3055

## 탈출

### 문제
사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다. 이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.

티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '\*', 돌은 'X'로 표시되어 있다. 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.

티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 이동할 수 있으면 고슴도치가 물에 빠지기 때문이다.

### 입력
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 'D'와 'S'는 하나씩만 주어진다.

### 출력
첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/3055>

### 예제 입력 1
3 3
D.*
...
.S.

### 예제 출력 1
3

### solve
- 먼저, 각 위치에 물이 도달하는데 걸리는 시간을 waterFlow()함수에서 water에 기록한다.(BFS)
- 고슴도치의 시작 위치에서 bfs를 시작하여 비버의 굴 까지 도착하는데 걸리는 시간을 구한다.
  - 이 때, 물이 찰 예정인 지역으로 이동할 수 없기 때문에 water에 기록된 시간보다 작은 경우만 고슴도치가 이동할 수 있는 조건을 추가한다.
  - 물이 이동 가능한 지역은 시간을 기록하고 나머지 지역에는 -1이 존재한다.
- 비버의 굴에 도착했을 때의 시간을 기록한 후 종료한다.
  - bfs가 종료된 이후 비버의 굴에 방문하지 못했다면 "KAKTUS" , 방문했다면 시간 출력


### 코드 설명
```C++
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
```
