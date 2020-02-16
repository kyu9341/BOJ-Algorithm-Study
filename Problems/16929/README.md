# Problem 16929

## Two Dots

### 문제
Two Dots는 Playdots, Inc.에서 만든 게임이다. 게임의 기초 단계는 크기가 N×M인 게임판 위에서 진행된다.


각각의 칸은 색이 칠해진 공이 하나씩 있다. 이 게임의 핵심은 같은 색으로 이루어진 사이클을 찾는 것이다.

다음은 위의 게임판에서 만들 수 있는 사이클의 예시이다.


점 k개 d1, d2, ..., dk로 이루어진 사이클의 정의는 아래와 같다.

- 모든 k개의 점은 서로 다르다.
- k는 4보다 크거나 같다.
- 모든 점의 색은 같다.
- 모든 1 ≤ i ≤ k-1에 대해서, di와 di+1은 인접하다. 또, dk와 d1도 인접해야 한다. 두 점이 인접하다는 것은 각각의 점이 들어있-는 칸이 변을 공유한다는 의미이다.

게임판의 상태가 주어졌을 때, 사이클이 존재하는지 아닌지 구해보자.

2 ≤ N, M ≤ 50

### 입력
첫째 줄에 게임판의 크기 N, M이 주어진다. 둘째 줄부터 N개의 줄에 게임판의 상태가 주어진다. 게임판은 모두 점으로 가득차 있고, 게임판의 상태는 점의 색을 의미한다. 점의 색은 알파벳 대문자 한 글자이다.

### 출력
사이클이 존재하는 경우에는 "Yes", 없는 경우에는 "No"를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/16929>

### 예제 입력 1
3 4
AAAA
ABCA
AAAA

### 예제 출력 1
Yes

### 예제 입력 2
3 4
AAAA
ABCA
AADA

### 예제 출력 2
No

### 예제 입력 3
4 4
YYYR
BYBY
BBBY
BBBY

### 예제 출력 3
Yes

### 예제 입력 4
7 6
AAAAAB
ABBBAB
ABAAAB
ABABBB
ABAAAB
ABBBAB
AAAAAB

### 예제 출력 4
Yes

### 예제 입력 5
2 13
ABCDEFGHIJKLM
NOPQRSTUVWXYZ

### 예제 출력 5
No

### solve
- 문제에서 주어진 조건에 맞는 사이클이 형성되는지 찾는 문제이다. dfs를 통해 해결할 수 있다.
- 방문 여부를 체크할 배열과 탐색을 시작한 점부터 이동한 거리를 나타낼 배열을 선언한다.

- 인접한 같은 색깔의 점인 경우 dfs를 수행한다.
	- 이때, 사이클을 이루는지 여부를 확인하는 방법은 다음과 같다.
		- cnt변수를 탐색을 진행할 때마다 1씩 증가시킨다.
		- 처음 방문하게 되는 점의 dist배열에 현재 cnt를 저장한다.
		- 재귀를 수행할 때 이미 방문했던 노드이며, (cnt - dist[x][y] >= 4) 인 경우 사이클이 형성된다.

- 사이클이 형성되지 않는 경우

![cycle](https://github.com/kyu9341/BOJ-Algorithm-Study/blob/master/pictures/cycle2.png)

- 사이클이 형성되는 경우

![cycle](https://github.com/kyu9341/BOJ-Algorithm-Study/blob/master/pictures/cycle1.png)




### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
char color[50][50];
bool check[50][50];
int dist[50][50]; // 시작점부터 이동한 거리
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, m; // 게임판의 크기

bool dfs(int x, int y, int cnt)
{
	if (check[x][y]) // 이미 방문했던 노드인데
	{
		if (cnt - dist[x][y] >= 4) // 이동 횟수에서 현재 위치에 저장된 시작점과의 거리 차가 4 이상 = 싸이클
			return true;
		else
			return false;
	}

	check[x][y] = true;
	dist[x][y] = cnt; // 현재 x,y가 시작점에서 몇번 이동했는지 저장, 시작점은 0

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (color[nx][ny] == color[x][y]) // 같은 색깔의 점인 경우(방문여부는 관계x)
			{
				if (dfs(nx, ny, cnt + 1))
					return true;
			}
		}
	}
	return false;
}

int main(void)
{
	cin >> n >> m;

	cin.ignore();
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		for (int j = 0; j < m; j++)
		{
			color[i][j] = str[j];
		}
	}

	string ans = "No";
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (check[i][j] == false)
			{
				if (dfs(i, j, 0))
					ans = "Yes";
			}
		}
	cout << ans << '\n';
}

```
