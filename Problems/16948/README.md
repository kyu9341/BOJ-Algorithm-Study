# Problem 16948

## 데스 나이트

### 문제
게임을 좋아하는 큐브러버는 체스에서 사용할 새로운 말 "데스 나이트"를 만들었다. 데스 나이트가 있는 곳이 (r, c)라면, (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 이동할 수 있다.

크기가 N×N인 체스판과 두 칸 (r1, c1), (r2, c2)가 주어진다. 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 구해보자. 체스판의 행과 열은 0번부터 시작한다.

데스 나이트는 체스판 밖으로 벗어날 수 없다.

### 입력
첫째 줄에 체스판의 크기 N(5 ≤ N ≤ 200)이 주어진다. 둘째 줄에 r1, c1, r2, c2가 주어진다.

### 출력
첫째 줄에 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 출력한다. 이동할 수 없는 경우에는 -1을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/16948>

### 예제 입력 1
7
6 6 0 1

### 예제 출력 1
4

### 예제 입력 2
6
5 1 0 5

### 예제 출력 2
-1

### 예제 입력 3
7
0 3 4 3

### 예제 출력 3
2

### solve
- bfs를 이용하여 최소 이동 횟수를 구한다.
- 시작 좌표를 큐에 넣고 이동 가능한 모든 경우를 확인한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int dx[] = { -2, -2, 0, 0, 2, 2 }; // (x, y)로 이동 가능한 상대 좌표
int dy[] = { -1, 1, -2, 2, -1, 1 };
bool check[201][201];
int dist[201][201];

int main(void)
{
	int n;
	cin >> n;

	int sr, sc, er, ec; // 시작점, 도착점
	cin >> sr >> sc >> er >> ec;

	memset(dist, -1, sizeof(dist)); // 거리를 모두 -1로 초기화

	queue<pair<int, int>> q;
	q.push(make_pair(sr, sc)); // 시작 좌표 push
	check[sr][sc] = true;
	dist[sr][sc] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) // 이동 가능한 모든 경우 확인
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) // 범위 내에서
			{
				if (check[nx][ny] == false) // 아직 확인하지 않은 경우
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1; // 다음 좌표 push 후 거리 추가
				}
			}
		}

	}

	cout << dist[er][ec] << '\n';
}

```
