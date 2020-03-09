# Problem 16954

## 움직이는 미로 탈출

### 문제
욱제는 학교 숙제로 크기가 8×8인 체스판에서 탈출하는 게임을 만들었다. 체스판의 모든 칸은 빈 칸 또는 벽 중 하나이다. 욱제의 캐릭터는 가장 왼쪽 아랫 칸에 있고, 이 캐릭터는 가장 오른쪽 윗 칸으로 이동해야 한다.

이 게임의 특징은 벽이 움직인다는 점이다. 1초마다 모든 벽이 아래에 있는 행으로 한 칸씩 내려가고, 가장 아래에 있어서 아래에 행이 없다면 벽이 사라지게 된다. 욱제의 캐릭터는 1초에 인접한 한 칸 또는 대각선 방향으로 인접한 한 칸으로 이동하거나, 현재 위치에 서 있을 수 있다. 이동할 때는 빈 칸으로만 이동할 수 있다.

1초 동안 욱제의 캐릭터가 먼저 이동하고, 그 다음 벽이 이동한다. 벽이 캐릭터가 있는 칸으로 이동하면 더 이상 캐릭터는 이동할 수 없다.

욱제의 캐릭터가 가장 오른쪽 윗 칸으로 이동할 수 있는지 없는지 구해보자.

### 입력
8개 줄에 걸쳐서 체스판의 상태가 주어진다. '.'은 빈 칸, '#'는 벽이다. 가장 왼쪽 아랫칸은 항상 벽이 아니다.

### 출력
욱제의 캐릭터가 가장 오른쪽 윗 칸에 도착할 수 있으면 1, 없으면 0을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/16954>

### 예제 입력 1
........
........
........
........
........
........
........
........

### 예제 출력 1
1

### 예제 입력 2
........
........
........
........
........
........
\##......
........

### 예제 출력 2
0

### 예제 입력 3
........
........
........
........
........
.#......
\#.......
.#......

### 예제 출력 3
0

### 예제 입력 4
........
........
........
........
........
.#######
\#.......
........

### 예제 출력 4
1

### 예제 입력 5
........
........
........
........
\#.......
.#######
\#.......
........

### 예제 출력 5
0

### solve
- 큐를 두 개 사용하여 하나의 큐에 존재하는 모든 원소에 대해 탐색하여 1초의 상황을 모두 학인한다.
- 현재 큐에서 탐색한 다음 좌표를 나머지 하나의 큐에 넣고, 벽을 이동시킨다.
- 두 큐를 오가며 위의 과정을 반복한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
int a[8][8];
bool check[8][8];
int dx[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, 1, -1, -1 };

void printA() // 벽의 이동 확인
{
	cout << '\n';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void move() // 벽을 이동시키는 함수
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			if (i == 0)
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = a[i - 1][j];
			}
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			char input;
			cin >> input;
			if (input == '.') a[i][j] = 0; // . : 0, # : 1로 변환
			else a[i][j] = 1;
		}
	pair<int, int> start = make_pair(7, 0); // 시작 지점
	pair<int, int> end = make_pair(0, 7); // 목표 지점

	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	q.push(start); // 가장 아래 칸

	while (!q.empty() || !nq.empty()) // 두 큐가 모두 비워질 때까지
	{
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (a[x][y] == 1) continue; // 캐릭터의 위치에 벽이 온 경우

			if (x == end.first && y == end.second) // 목표 지점에 도달한 경우
			{
				cout << 1 << '\n';
				return 0;
			}

			nq.push(make_pair(x, y)); // 제자리에 위치하는 경우

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) // 범위 내에서
				{
					if (a[nx][ny] == 0) // 다음 좌표가 빈 칸인 경우
					{
						nq.push(make_pair(nx, ny)); // 8방향 추가
					}
				}
			}

		} // 1초가 모두 끝난 후
		move(); // 벽 이동

		while (!nq.empty())
		{
			int x = nq.front().first;
			int y = nq.front().second;
			nq.pop();

			if (a[x][y] == 1) continue;  // 캐릭터의 위치에 벽이 온 경우

			if (x == end.first && y == end.second) // 목표 지점에 도달한 경우
			{
				cout << 1 << '\n';
				return 0;
			}

			q.push(make_pair(x, y));

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8)
				{
					if (a[nx][ny] == 0) // 다음 좌표가 빈 칸인 경우
					{
						q.push(make_pair(nx, ny)); // 8방향 추가
					}
				}
			}

		} // 1초가 끝난 후
		move(); // 벽 이동

	}

	cout << 0 << '\n';
}

```
