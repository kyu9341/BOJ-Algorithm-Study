# Problem 2665

## 미로만들기

### 문제
n×n 바둑판 모양으로 총 n2개의 방이 있다. 일부분은 검은 방이고 나머지는 모두 흰 방이다. 검은 방은 사면이 벽으로 싸여 있어 들어갈 수 없다. 서로 붙어 있는 두 개의 흰 방 사이에는 문이 있어서 지나다닐 수 있다. 윗줄 맨 왼쪽 방은 시작방으로서 항상 흰 방이고, 아랫줄 맨 오른쪽 방은 끝방으로서 역시 흰 방이다.

시작방에서 출발하여 길을 찾아서 끝방으로 가는 것이 목적인데, 아래 그림의 경우에는 시작방에서 끝 방으로 갈 수가 없다. 부득이 검은 방 몇 개를 흰 방으로 바꾸어야 하는데 되도록 적은 수의 방의 색을 바꾸고 싶다.

아래 그림은 n=8인 경우의 한 예이다.

위 그림에서는 두 개의 검은 방(예를 들어 (4,4)의 방과 (7,8)의 방)을 흰 방으로 바꾸면, 시작방에서 끝방으로 갈 수 있지만, 어느 검은 방 하나만을 흰 방으로 바꾸어서는 불가능하다. 검은 방에서 흰 방으로 바꾸어야 할 최소의 수를 구하는 프로그램을 작성하시오.

단, 검은 방을 하나도 흰방으로 바꾸지 않아도 되는 경우는 0이 답이다.

### 입력
첫 줄에는 한 줄에 들어가는 방의 수 n(1≤n≤50)이 주어지고, 다음 n개의 줄의 각 줄마다 0과 1이 이루어진 길이가 n인 수열이 주어진다. 0은 검은 방, 1은 흰 방을 나타낸다.

### 출력
첫 줄에 흰 방으로 바꾸어야 할 최소의 검은 방의 수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2665>

### 예제 입력 1
8
11100110
11010010
10011010
11101100
01000111
00110001
11011000
11000111

### 예제 출력 1
2

### solve
- 흰 방으로 바꾸어야 하는 최소 개수만 구하면 되므로 visited배열에 현재 위치까지 오는데 검은 방을 흰 방으로 바꾸어야 하는 최소 개수를 저장한다.
- bfs를 수행하며 더 적은 횟수로 현재 위치에 도달하는 경우만 값을 갱신하며 (n - 1, n - 1)까지 이동한다.
- 이후, visited[n - 1][n - 1]을 출력한다.

### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int MAX = 50;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int a[MAX][MAX];
int visited[MAX][MAX]; // 현재 위치까지 최소로 방을 바꾸어야 하는 개수
int n;

struct place {
	int x;
	int y;

	place(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void bfs() {
	queue<place> q;
	q.push(place(0, 0));
	visited[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) { // 범위 내에서
				if (a[nx][ny] == 1) { // 흰 방인 경우
					// 아직 방문하지 않았거나 더 적은 횟수로 이동 가능한 경우
					if (visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y]) {
						visited[nx][ny] = visited[x][y];
						q.push(place(nx, ny));
					}
				}
				else { // 검은 방인 경우
					// 아직 방문하지 않았거나 더 적은 횟수로 이동 가능한 경우
					if (visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y] + 1) {
						visited[nx][ny] = visited[x][y] + 1;
						q.push(place(nx, ny));
					}
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin.ignore();
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++)
			a[i][j] = str[j] - '0';
	}

	memset(visited, -1, sizeof(visited));
	bfs();

	cout << visited[n - 1][n - 1] << '\n';

}
```
