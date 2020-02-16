# Problem 2178

## 미로 탐색

### 문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1

1	0	1	0	1	0

1	0	1	0	1	1

1	1	1	0	1	1

미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

### 입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

### 출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

### 문제 링크
<https://www.acmicpc.net/problem/2178>

### 예제 입력 1
4 6
101111
101010
101011
111011

### 예제 출력 1
15

### 예제 입력 2
4 6
110110
110110
111111
111101

### 예제 출력 2
9

### 예제 입력 3
2 25
1011101110111011101110111
1110111011101110111011101

### 예제 출력 3
38

### 예제 입력 4
7 7
1011111
1110001
1000001
1000001
1000001
1000001
1111111

### 예제 출력 4
13

### solve
- 최단 거리를 구하는 문제라고 볼 수 있으므로 bfs를 이용한다.
- dist배열에 이동가능한 각 칸의 (0,0)에서의 거리를 저장한다.
	- dist[0][0] = 1을 두고 다음 좌표에 1씩 더해 저장
- 이동 가능한 방향(상하좌우)를 dx, dy에 저장하여 탐색
- bfs로 탐색 후 dist[n - 1][m - 1]을 구하면 된다.
	- (1,1)이 아닌 (0,0)부터 시작했으므로



### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
int a[101][101];
bool check[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int dist[101][101]; // (0, 0)에서부터의 거리
int n, m; // 미로의 행(세로), 열(가로)

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	dist[0][0] = 1;

	while (!q.empty())
	{
		x = q.front().first; // 현재 좌표
		y = q.front().second;
		q.pop(); // 좌표 저장 후 pop (bfs)

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i]; // 다음 좌표
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) // 미로의 범위 내에서
			{
				if (check[nx][ny] == false && a[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny)); // 방문할 때 push
					check[nx][ny] = true; // 방문 처리
					dist[nx][ny] = dist[x][y] + 1; // (0, 0)을 1로 시작하여 거리 계산
				}
			}
		}

	}
}

int main(void)
{
	cin >> n >> m;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < str.length(); j++)
			a[i][j] = int(str[j] - '0'); // 정수로 변환
	}
	bfs(0, 0);

	cout << dist[n - 1][m - 1] << '\n';

}

```
