# Problem 14499

## 주사위 굴리기

### 문제
크기가 N×M인 지도가 존재한다. 지도의 오른쪽은 동쪽, 위쪽은 북쪽이다. 이 지도의 위에 주사위가 하나 놓여져 있으며, 주사위의 전개도는 아래와 같다. 지도의 좌표는 (r, c)로 나타내며, r는 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수이다.
```
  2
4 1 3
  5
  6
```
주사위는 지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있으며, 놓여져 있는 곳의 좌표는 (x, y) 이다. 가장 처음에 주사위에는 모든 면에 0이 적혀져 있다.

지도의 각 칸에는 정수가 하나씩 쓰여져 있다. 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.

주사위를 놓은 곳의 좌표와 이동시키는 명령이 주어졌을 때, 주사위가 이동했을 때 마다 상단에 쓰여 있는 값을 구하는 프로그램을 작성하시오.

주사위는 지도의 바깥으로 이동시킬 수 없다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.

### 입력
첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N, M ≤ 20), 주사위를 놓은 곳의 좌표 x y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 그리고 명령의 개수 K (1 ≤ K ≤ 1,000)가 주어진다.

둘째 줄부터 N개의 줄에 지도에 쓰여 있는 수가 북쪽부터 남쪽으로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 주사위를 놓은 칸에 쓰여 있는 수는 항상 0이다. 지도의 각 칸에 쓰여 있는 수는 10을 넘지 않는 자연수 또는 0이다.

마지막 줄에는 이동하는 명령이 순서대로 주어진다. 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.

### 출력
이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력한다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.

### 문제 링크
<https://www.acmicpc.net/problem/14499>

### 예제 입력 1
4 2 0 0 8
0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2

### 예제 출력 1
0
0
3
0
0
8
6
3

### 예제 입력 2
3 3 1 1 9
1 2 3
4 0 5
6 7 8
1 3 2 2 4 4 1 1 3

### 예제 출력 2
0
0
0
3
0
1
0
6
0

### 예제 입력 3
2 2 0 0 16
0 2
3 4
4 4 4 4 1 1 1 1 3 3 3 3 2 2 2 2

### 예제 출력 3
0
0
0
0

### 예제 입력 4
3 3 0 0 16
0 1 2
3 4 5
6 7 8
4 4 1 1 3 3 2 2 4 4 1 1 3 3 2 2

### 예제 출력 4
0
0
0
6
0
8
0
2
0
8
0
2
0
8
0
2

### solve
- 각 주사위의 면의 변화를 기록하여 좌표의 값에 따른 동작을 잘 구현하면 된다.
- 벡터에 명령을 저장했고, 명령에 따른 주사위의 이동을 주사위의 각 면에 해당하는 변수를 만들어 구현하였다.
- 예를 들어, 명령 1을 받아 동쪽으로 이동하는 경우를 살펴보자.
	- 다음 좌표가 지도의 범위 내에 있는지 확인하여 지도의 범위가 아니라면 해당 명령을 무시하고 다음 명령을 수행한다.
	- 지도의 범위라면 동쪽으로 이동하므로 바닥면은 동쪽을 보게 되고, 동쪽을 보던 면은 윗면, 윗면은 서쪽 면, 서쪽 면은 바닥면으로 이동하게 된다.
	- 이 때, 지도의 칸이 0이라면 주사위의 바닥면을 복사하고, 아니라면 지도의 칸을 주사위의 바닥면으로 복사한다.
	- 이후 x, y를 갱신하여 반복을 이어간다.


### 코드 설명
```C++
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
int a[21][21];
int dice[3][3];
int n, m, k;

bool check(int x, int y) // 현재 x,y가 범위에 속하는지 확인
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return true;
	else return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x, y;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	vector<int> cmd(k); // 명령어 저장
	for (int i = 0; i < k; i++)
		cin >> cmd[i];

	// 주사위의 6면
	int bottom = 0;
	int top = 0;
	int north = 0;
	int south = 0;
	int east = 0;
	int west = 0;

	for (int i = 0; i < k; i++)
	{
		int nx, ny;
		switch (cmd[i])
		{
		case 1: // 동쪽으로 이동하는 경우
			nx = x; // 다음 좌표
			ny = y + 1;
			if (check(nx, ny))
			{ // 주사위의 각 면 이동
				int temp = bottom;
				bottom = east;
				east = top;
				top = west;
				west = temp;
				if (a[nx][ny] == 0) // 지도의 칸이 0인 경우
					a[nx][ny] = bottom; // 주사위의 바닥면이 복사
				else
				{
					bottom = a[nx][ny]; // 0이 아니면 주사위의 바닥면으로 복사
					a[nx][ny] = 0; // 지도의 칸은 0으로 변경
				}
			}
			else continue; // 범위를 벗어난 경우 해당 명령 무시
			x = nx;
			y = ny;
			break;
		case 2: // 서쪽으로 이동하는 경우
			nx = x;
			ny = y - 1;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = west;
				west = top;
				top = east;
				east = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		case 3: // 북쪽으로 이동하는 경우
			nx = x - 1;
			ny = y;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = north;
				north = top;
				top = south;
				south = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		case 4: // 남쪽으로 이동하는 경우
			nx = x + 1;
			ny = y;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = south;
				south = top;
				top = north;
				north = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		}
		cout << top << '\n'; // 윗면 출력

	}

}
```
