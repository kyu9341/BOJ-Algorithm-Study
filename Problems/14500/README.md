# Problem 14500

## 테트로미노

### 문제
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안 된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.



아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.
### 입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

### 출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/14500>

### 예제 입력 1
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1

### 예제 출력 1
19

### 예제 입력 2
4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

### 예제 출력 2
20

### 예제 입력 3
4 10
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1

### 예제 출력 3
7


### solve
- 5가지의 경우 중 ㅜ 모양을 제외한 4가지 경우는 한 점에서 시작하여 3개의 칸을 연속해서 방문하는 형태이므로 dfs를 통해 구할 수 있다.
  - dfs를 사용하여 네 칸을 연속해서 방문하는 경우 네 칸의 최댓값을 구한다.
- 나머지 ㅜ 모양은 3개의 칸을 연속해서 방문하지 않으므로 경우 dfs로는 구할 수 없다.
  - 따라서 반복문에 직접 구현하였다.
  - ㅗ, ㅜ 모양인 경우 j + 2 < m 일 때를 기준으로 처리하였고,
  - ㅓ, ㅏ 모양인 경우 i + 2 < n 일 때를 기준으로 처리하였다.


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>

using namespace std;
const int MAX = 500;
int n, m;
int a[MAX + 1][MAX + 1];
bool check[MAX + 1][MAX + 1];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0 , 0 };
int ans = 0;

void dfs(int x, int y, int sum, int index) // 한 점에서 시작하여 3개의 칸을 연속해서 확인하는 경우 모두 확인
{
	check[x][y] = true;
	if (index == 4)
	{
		if (sum > ans) ans = sum; // 네 칸의 합의 최댓값
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (check[nx][ny] == false)
			{
				dfs(nx, ny, sum + a[x][y], index + 1);
				check[nx][ny] = false; // 방문 처리 해제
			}
		}
	}
	check[x][y] = false; // 시작점 방문 처리 해제
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, 0, 0);
			// dfs로 구할 수 없는 한 가지 경우 처리
			if (j + 2 < m) //  ㅗ, ㅜ 모양 처리
			{
				int tmp1 = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0)
				{
					int tmp2 = tmp1 + a[i - 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
				if (i + 1 < n)
				{
					int tmp2 = tmp1 + a[i + 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
			}
			if (i + 2 < n) // ㅓ, ㅏ 모양 처리
			{
				int tmp1 = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j - 1 >= 0)
				{
					int tmp2 = tmp1 + a[i + 1][j - 1];
					if (ans < tmp2) ans = tmp2;
				}
				if (j + 1 < m)
				{
					int tmp2 = tmp1 + a[i + 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
			}
		}

	cout << ans << '\n';
}

```
