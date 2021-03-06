# Problem 2667

## 단지번호 붙이기

### 문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

### 입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

### 출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

### 문제 링크
<https://www.acmicpc.net/problem/2667>

### 예제 입력 1
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

### 예제 출력 1
3
7
8
9

### solve
- 인접한 집들을 찾아 단지를 정의하고 개수를 파악하면 된다. dfs 또는 bfs를 통해 구현하면 될 것이다.
- dfs로 구현
- 이때, 따로 인접 리스트를 만들지 않고 x, y 좌표를 통해 상하좌우로 다음 좌표를 정해 탐색을 수행한다.
	- dx, dy라는 배열에 상하좌우로 이동할 좌표를 기록해 두어 반복문을 통해 다음 좌표를 탐색한다.
- 인접한 집들 별로 단지번호를 붙여준다.(이미 탐색을 수행했는지도 파악)
- 모든 좌표를 확인하여 단지 번호를 붙이고 새로운 배열에 같은 단지 번호를 가지는 주택의 수를 파악하여 저장한다.
	- 이후 count(단지번호 수)만큼 정렬을 수행하여 오름차순으로 출력한다.
- bfs로 구현
	- x, y 좌표를 pair로 묶어 queue에 push
	- dfs와 같은 방식으로 구현


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>

using namespace std;

int d[25][25]; // 단지 번호를 기록할 배열
int a[25][25]; // 집의 유무를 기록할 배열
int dx[] = { 0, 0, 1, -1 }; // 상하좌우 이동 좌표
int dy[] = { 1, -1, 0, 0 };
int n; // 지도의 크기

void dfs(int x, int y, int count)
{
	d[x][y] = count; // 현재 좌표의 단지 번호를 붙임

	for (int i = 0; i < 4; i++) // 상하좌우 탐색
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n) // 지도의 범위 내에서
		{
			if (a[nx][ny] == 1 && d[nx][ny] == 0) // 다음번 좌표에 집이 있고, 아직 탐색하지 않은 경우(단지 번호가 안붙어있는 경우)
			{
				dfs(nx, ny, count);
			}
		}
	}

}

void bfs(int x, int y, int count)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = count; // 현재 좌표에 단지번호 붙이기

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop(); // 맨 앞 좌표 저장후 pop

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n)
			{
				if (a[nx][ny] == 1 && d[nx][ny] == 0) // 다음 좌표가 육지이고 아직 방문하지 않은 경우
				{
					q.push(make_pair(nx, ny)); // 다음 좌표 push
					d[nx][ny] = count; // 방문처리 and 단지번호 붙이기
				}
			}
		}
	}

}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%1d", &a[i][j]); // 한자리씩 입력


	int count = 0; // 단지 번호(연결 요소의 개수)
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1 && d[i][j] == 0) // 현재 좌표에 집이 있고 탐색되지 않은 경우
			{

				bfs(i, j, count + 1);
				// dfs(i, j, count + 1);
				count++;
			}

		}

	int ans[25 * 25] = { 0 };

	cout << count << '\n';

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ans[d[i][j]]++; // 단지번호 별 주택의 개수 파악
		}

	sort(ans + 1, ans + count + 1); // 단지 번호를 1부터 붙였으므로


	for (int i = 1; i <= count; i++)
		cout << ans[i] << '\n';

}

```
