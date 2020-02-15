# Problem 4963

## 섬의 개수

### 문제
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.

한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 지도는 바다로 둘러쌓여 있으며, 지도 밖으로 나갈 수 없다.

### 입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

### 출력
각 테스트 케이스에 대해서, 섬의 개수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/4963>

### 예제 입력 1
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0

### 예제 출력 1
0
1
1
3
1
9

### solve
- 단지번호 붙이기 문제와 유사하다. dfs 또는 bfs로 구현할 수 있다.
	- 결국 연결 요소의 개수를 구하는 문제이다.
- dfs로 구현
- 이때, 따로 인접 리스트를 만들지 않고 x, y 좌표를 통해 상하좌우로 다음 좌표를 정해 탐색을 수행한다.
	- dx, dy라는 배열에 상하좌우, 대각선으로 이동할 좌표를 기록해 두어 반복문을 통해 다음 좌표를 탐색한다.
- 현재 위치에서 8방을 탐색하며 다음 좌표가 육지이고 아직 방문하지 않은 경우에 재귀를 수행한다.



### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int a[50][50];
bool check[50][50];
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 }; // 상하좌우 대각선
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int w, h; // 너비, 높이


void dfs(int x, int y)
{
	check[x][y] = true; // 방문 처리

	for (int i = 0; i < 8; i++) // 상하좌우, 대각선 탐색 (8방)
	{
		int nx = x + dx[i]; // 다음 x좌표
		int ny = y + dy[i]; // 다음 y좌표

		if (nx >= 0 && ny >= 0 && nx < h && ny < w) // 지도의 범위 내부
		{
			if (a[nx][ny] == 1 && check[nx][ny] == false) // 다음 좌표가 육지이고 방문하지 않았다면
			{
				dfs(nx, ny);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> a[i][j];

		memset(check, false, sizeof(check)); // check 초기화

		int count = 0; // 연결요소의 개수
		for(int x = 0; x < h; x++)
			for (int y = 0; y < w; y++)
			{
				if (a[x][y] == 1 && check[x][y] == false) // 현재 좌표가 육지이고 방문하지 않은 경우
				{
					count++; // 연결 요소 카운트
					dfs(x, y);
				}
			}
		cout << count << '\n';
	}
}
```
