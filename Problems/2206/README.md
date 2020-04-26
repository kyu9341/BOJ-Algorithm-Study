# Problem 2206

## 벽 부수고 이동하기

### 문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

### 입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

### 출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2206>

### 예제 입력 1
6 4
0100
1110
1000
0000
0111
0000

### 예제 출력 1
15

### 예제 입력 2
4 4
0111
1111
1111
1110

### 예제 출력 2
-1


### solve
- bfs를 이용하여 큐에 좌표와 벽을 부쉈는지 여부를 담는다.
- 3차원 배열 dist를 -1로 초기화하고 각 위치, 벽을 부쉈는지 여부에 해당하는 이동거리를 담는다.
- bfs를 수행하며 다음 위치가 이동 가능하다면 그냥 이동하는 경우와 다음 위치가 벽인데 아직 부수지 않았을 때 벽을 부수고 이동하는 경우를 모두 큐에 넣어 확인한다.
- 목적지까지 도달 가능하다면 벽을 부순 경우와 부수지 않은 경우중 더 짧은 경로를 리턴한다.

### 코드 설명
```C++
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

```
