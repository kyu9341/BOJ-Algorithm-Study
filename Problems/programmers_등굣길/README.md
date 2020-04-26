# 프로그래머스 - 등굣길

## 등굣길

### 문제
계속되는 폭우로 일부 지역이 물에 잠겼습니다. 물에 잠기지 않은 지역을 통해 학교를 가려고 합니다. 집에서 학교까지 가는 길은 m x n 크기의 격자모양으로 나타낼 수 있습니다.

아래 그림은 m = 4, n = 3 인 경우입니다.

가장 왼쪽 위, 즉 집이 있는 곳의 좌표는 (1, 1)로 나타내고 가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는 (m, n)으로 나타냅니다.

격자의 크기 m, n과 물이 잠긴 지역의 좌표를 담은 2차원 배열 puddles이 매개변수로 주어집니다. 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 return 하도록 solution 함수를 작성해주세요.

### 제한사항
- 격자의 크기 m, n은 1 이상 100 이하인 자연수입니다.
	- m과 n이 모두 1인 경우는 입력으로 주어지지 않습니다.
- 물에 잠긴 지역은 0개 이상 10개 이하입니다.
- 집과 학교가 물에 잠긴 경우는 입력으로 주어지지 않습니다.

### 입출력 예
m	n	puddles	return
4	3	[[2, 2]]	4

### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/42898>

### solve
- 그림만 보고 dfs, bfs문제인가 했지만 dp문제였다..
- 점화식은 다음과 같이 세울 수 있다.
 	- d[m][n] = (m, n)까지 오는 최단 거리의 개수
	- d[m][n] = d[m - 1][n] + d[m][n - 1]


### 코드 설명
```C++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100;
long long mod = 1000000007;
long long d[MAX + 1][MAX + 1];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	// 초기값 설정
	d[1][1] = 1;
	d[1][2] = 1;
	d[2][1] = 1;

	// 물에 잠긴 위치 표시
	for (int i = 0; i < puddles.size(); i++) {
		d[puddles[i][0]][puddles[i][1]] = -1;
	}

	// d[m][n] = (m, n)까지 오는 최단 거리의 개수
	// d[m][n] = d[m - 1][n] + d[m][n - 1]
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == -1)
				d[i][j] = 0;
			else if(d[i][j] == 0)
				d[i][j] = d[i - 1][j] + d[i][j - 1];
			d[i][j] %= mod;
		}
	}

	answer = d[m][n] % mod;


	return answer;
}
```
