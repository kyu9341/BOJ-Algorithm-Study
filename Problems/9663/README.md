# Problem 9663

## N-Queen

### 문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

### 출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/9663>

### 예제 입력 1
8

### 예제 출력 1
92

### solve
- 퀸은 같은 행, 열, 대각선의 모든 칸으로 이동이 가능하므로 동일 행, 열, 대각선에 두 개 이상의 퀸을 놓을 수 없다.
- n * n에 n개를 놓는 경우이므로 한 행에는 한개의 퀸만이 놓일 수 있다.
	- 이를 기준으로 재귀를 수행하며 check[row][col]에 퀸을 놓은 위치를 기록한다.
	- possible함수로 현재 위치에  퀸을 놓을 수 있는지 판별하여 가능하다면 퀸을 놓고 재귀를 수행한다.
		- possible함수 : 첫 번째 행부터 차례로 퀸을 놓아 내려가고 있으므로 이전 행의 같은 열, 좌측 위 대각선, 우측 위 대각선을 확인하며 퀸이 놓였는지 확인한다.
- row가 n과 같아졌다면 한 행에 하나의 퀸을 모두 놓은 경우이므로 방법의 수를 1증가시킨다.


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;
bool check[15][15];
int n;
int ans = 0;

bool possible(int x, int y) // (x, y)에 퀸을 놓을 수 있는지 판별하는 함수
{
	for (int i = x - 1, j = 1; i >= 0; i--, j++)
	{
		if (check[i][y]) return false; // 같은 열에 놓인 퀸이 있는지 확인
		if (y - j >= 0 && check[i][y - j]) return false; // 좌측 위 대각선 확인
		if (y + j < n && check[i][y + j]) return false; // 우측 위 대각선 확인
	}
	return true;
}

void go(int row)
{
	if (row == n) // 놓을 수 있는 경우
	{
		ans++;
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (possible(row, col)) // 현재 (row, col)에 퀸을 놓을 수 있는지 확인
		{
			check[row][col] = true; // 놓은 것을 표시
			go(row + 1);
			check[row][col] = false;
		}
	}
}

int main(void)
{
	cin >> n;
	go(0);

	cout << ans << '\n';
}

```
