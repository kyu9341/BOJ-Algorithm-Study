# Problem 1261

## 알고스팟

### 문제
알고스팟 운영진이 모두 미로에 갇혔다. 미로는 N*M 크기이며, 총 1*1크기의 방으로 이루어져 있다. 미로는 빈 방 또는 벽으로 이루어져 있고, 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.

알고스팟 운영진은 여러명이지만, 항상 모두 같은 방에 있어야 한다. 즉, 여러 명이 다른 방에 있을 수는 없다. 어떤 방에서 이동할 수 있는 방은 상하좌우로 인접한 빈 방이다. 즉, 현재 운영진이 (x, y)에 있을 때, 이동할 수 있는 방은 (x+1, y), (x, y+1), (x-1, y), (x, y-1) 이다. 단, 미로의 밖으로 이동 할 수는 없다.

벽은 평소에는 이동할 수 없지만, 알고스팟의 무기 AOJ를 이용해 벽을 부수어 버릴 수 있다. 벽을 부수면, 빈 방과 동일한 방으로 변한다.

만약 이 문제가 알고스팟에 있다면, 운영진들은 궁극의 무기 sudo를 이용해 벽을 한 번에 다 없애버릴 수 있지만, 안타깝게도 이 문제는 Baekjoon Online Judge에 수록되어 있기 때문에, sudo를 사용할 수 없다.

현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 미로의 크기를 나타내는 가로 크기 M, 세로 크기 N (1 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 미로의 상태를 나타내는 숫자 0과 1이 주어진다. 0은 빈 방을 의미하고, 1은 벽을 의미한다.

(1, 1)과 (N, M)은 항상 뚫려있다.

### 출력
첫째 줄에 알고스팟 운영진이 (N, M)으로 이동하기 위해 벽을 최소 몇 개 부수어야 하는지 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1261>

### 예제 입력 1
3 3
011
111
110

### 예제 출력 1
3

### 예제 입력 2
4 2
0001
1000

### 예제 출력 2
0

### 예제 입력 3
6 6
001111
010000
001111
110001
011010
100010

### 예제 출력 3
2

### solve
- 벽과 빈 방으로 이루어진 미로를 탈출하는데, 벽을 몇개 부숴야 하는지 묻는 문제이다.
- 빈 방을 통과하는 경우 가중치가 0이고 벽을 통과하면 가중치가 1이므로 bfs에서 덱을 사용하였다.
	- 빈 방(0)이 우선순위가 더 높으므로 덱의 맨 앞에 push 하고 부순 벽의 개수는 증가시키지 않는다.
	- 벽(1)은 덱의 맨 뒤에 push 하고 부순 벽의 개수를 1증가시킨다.
- (0,0)부터 시작했으므로 (n - 1, m - 1)을 구하면 정답이다.



### 코드 설명
```C++
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<deque>
#include<cstdio>

using namespace std;
const int MAX = 100;
int a[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main(void)
{
	int m, n; // m : 가로, n : 세로
	cin >> m >> n;
	cin.ignore();

	memset(dist, -1, sizeof(dist)); // -1로 초기화

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			a[i][j] = str[j] - '0';
	}

	deque<pair<int, int>> dq; // 덱 사용
	dq.push_back(make_pair(0, 0)); // 초기 위치
	dist[0][0] = 0;

	while (!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) // 범위 내에서
			{
				if (dist[nx][ny] == -1 && a[nx][ny] == 0) // 방문하지 않은 미로이고(-1) 빈 방인 경우(0)
				{
					dq.push_front(make_pair(nx, ny)); // 덱의 맨 앞에 push (빈 방이 우선순위)
					dist[nx][ny] = dist[x][y]; // 부순 벽의 개수는 유지
				}
				if (dist[nx][ny] == -1 && a[nx][ny] == 1) // 방문하지 않은 미로이고(-1) 벽인 경우(1)
				{
					dq.push_back(make_pair(nx, ny)); // 덱의 맨 뒤에 push
					dist[nx][ny] = dist[x][y] + 1; // 부순 벽의 개수 + 1
				}
			}
		}
	}
	cout << dist[n - 1][m - 1] << '\n'; // (0,0)부터 시작했으므로 (n - 1, m - 1)을 구함

}

```
