# Problem 7562

## 나이트의 이동

### 문제
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

### 입력
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

### 출력
각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/7562>

### 예제 입력 1
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1

### 예제 출력 1
5
28
0

### solve
- 나이트가 목표 지점까지 이동하는 최소 이동횟수를 구하는 문제이므로 bfs를 사용한다.
- 나이트가 이동할 수 있는 방향은 8개, 이동 가능한 위치의 상대 위치를 저장하여 탐색한다.
- d라는 배열에 각 위치까지의 이동 횟수를 기록한다.
	- 목표 위치의 d에 저장된 값을 출력한다.

### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 }; // x, y의 상대적 위치
int dy[] = { 1, 2, 2, 1, -1, -2, -2 ,-1 };
bool check[301][301];
int d[301][301]; // 이동 횟수
int n; // 한 변의 길이

bool isInside(int x, int y) // 체스판 내부인지 판별
{
	if (x >= 0 && y >= 0 && x < n && y < n)
		return true;
	else
		return false;
}

void bfs(int x, int y)
{
	memset(d, 0, sizeof(d)); // d, check 배열 초기화
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 0;
	check[x][y] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) // 8방향 모두 탐색
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny)) // 체스판 내부인지 확인
			{
				if (check[nx][ny] == false)
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = true; // 방문 처리
					d[nx][ny] = d[x][y] + 1; // 이동 횟수 추가
				}
			}
		}
	}
}
int main(void)
{
	int t; // test case
	cin >> t;

	while (t--)
	{
		cin >> n;
		int sx, sy, ex, ey;
		cin >> sx >> sy; // 시작 위치
		cin >> ex >> ey; // 마지막 위치

		bfs(sx, sy);

		cout << d[ex][ey] << '\n';

	}
}
```
