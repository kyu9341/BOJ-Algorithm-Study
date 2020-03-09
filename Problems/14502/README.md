# Problem 14502

## 연구소

### 문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

```
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
```

이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

```
2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
```

바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

```
2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
```

벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.

연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

빈 칸의 개수는 3개 이상이다.

### 출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/14502>

### 예제 입력 1
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

### 예제 출력 1
27

### 예제 입력 2
4 6
0 0 0 0 0 0
1 0 0 0 0 2
1 1 1 0 0 2
0 0 0 0 0 2

### 예제 출력 2
9

### 예제 입력 3
8 8
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

### 예제 출력 3
3

### solve
- 안전구역(0)에 벽(1)을 세 개 세워 바이러스를 막아야 한다.
- 벽을 세울 수 있는 구역(0)의 경우를 모두 구해 bfs로 바이러스를 퍼트린 후 감염되지 않은 구역의 개수의 최댓값을 구한다.
- 재귀함수로 벽의 세울 구역의 좌표의 조합을 구해 모든 경우를 탐색한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;
int a[10][10];
bool check[10][10];
int tmp[10][10];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> d; // 바이러스 감염 구역 좌표
vector<pair<int, int>> wall; // 벽을 세울 구역 좌표
int ans = 0;

int n, m;

int bfs() //  현재 지도 상태의 안전 영역 크기 리턴
{
	memset(check, false, sizeof(check)); // check 배열 초기화

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[i][j] = a[i][j]; // tmp에 a복사

	for (int i = 0; i < 3; i++)
		tmp[wall[i].first][wall[i].second] = 1; // 현재 구한 벽의 좌표 추가

	queue<pair<int, int>> q;
	for (int i = 0; i < d.size(); i++)
	{
		q.push(d[i]);
		check[d[i].first][d[i].second] = true; // 바이러스 감염 구역에서 bfs 시작
	}

	while (!q.empty()) // bfs
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < n && ny < m && nx >= 0 && ny >= 0) // 범위 내에서
			{
				if (!check[nx][ny] && tmp[nx][ny] == 0) // 방문하지 않았고, 안전 구역인 경우
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					tmp[nx][ny] = 2; // 감염시킨다.
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == 0)
				res++; // 안전 구역 개수 count
		}
	return res;
}

void go(int index, int start)
{
	if (index == 3)
	{
		int save = bfs();
		if (ans < save)
			ans = save; // 안전구역의 최댓값 저장
		return;
	}

	for (int i = start; i < n * m; i++) // 조합 구하기
	{ // 중복 제거
		if (a[i / m][i % m] == 0)
		{
			wall.push_back(make_pair(i / m, i % m));
			go(index + 1, i + 1); // 현재까지 벽의 개수, 다음 시작점
			wall.pop_back();
		}
	}
}

int main(void)
{
	cin >> n >> m;

	for(int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2) d.push_back(make_pair(i, j)); // 바이러스 감염 구역 저장
		}

	go(0, 0);

	cout << ans << '\n';

}

```
