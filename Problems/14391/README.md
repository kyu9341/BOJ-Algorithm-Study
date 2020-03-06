# Problem 14391

## 종이 조각

### 문제
영선이는 숫자가 쓰여 있는 직사각형 종이를 가지고 있다. 종이는 1×1 크기의 정사각형 칸으로 나누어져 있고, 숫자는 각 칸에 하나씩 쓰여 있다. 행은 위에서부터 아래까지 번호가 매겨져 있고, 열은 왼쪽부터 오른쪽까지 번호가 매겨져 있다.

영선이는 직사각형을 겹치지 않는 조각으로 자르려고 한다. 각 조각은 크기가 세로나 가로 크기가 1인 직사각형 모양이다. 길이가 N인 조각은 N자리 수로 나타낼 수 있다. 가로 조각은 왼쪽부터 오른쪽까지 수를 이어 붙인 것이고, 세로 조각은 위에서부터 아래까지 수를 이어붙인 것이다.

아래 그림은 4×4 크기의 종이를 자른 한 가지 방법이다.

4937
2591
3846
9150

각 조각의 합은 493 + 7160 + 23 + 58 + 9 + 45 + 91 = 7879 이다.

종이를 적절히 잘라서 조각의 합을 최대로 하는 프로그램을 작성하시오.

### 입력
첫째 줄에 종이 조각의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 4)

둘째 줄부터 종이 조각이 주어진다. 각 칸에 쓰여 있는 숫자는 0부터 9까지 중 하나이다.

### 출력
영선이가 얻을 수 있는 점수의 최댓값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/14391>

### 예제 입력 1
2 3
123
312

### 예제 출력 1
435

### 예제 입력 2
2 2
99
11

### 예제 출력 2
182

### 예제 입력 3
4 3
001
010
111
100

### 예제 출력 3
1131

### 예제 입력 4
1 1
8

### 예제 출력 4
8

### solve
- 종이를 가로로 이어 붙이는 칸을 0, 세로로 이어 붙이는 칸을 1로 하여 모든 경우를 탐색한다.
- 2차원 배열의 인덱스를 가로로 쭉 펴서 1차원 배열의 인덱스와 같이 만들어 index가 n*m이 될 때까지 재귀를 수행한다.
- 이후 dfs를 통해 각 지점과 연결된 가로 or 세로를 이어붙여 그 합을 구한다.
- 구한 합의 최댓값을 출력한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
int n, m; // 가로, 세로
int a[4][4];
bool check[4][4];
int xy[4][4]; // 0 : 가로로 합, 1 : 세로로 합
vector<int> ans;

int dfs(int x, int y, int sum) // 현재 위치부터 연결된 가로 또는 세로의 합을 리턴
{
	check[x][y] = true;
	if (xy[x][y] == 0) // 가로로 확인하는 경우
	{
		if (y + 1 < m && xy[x][y] == xy[x][y + 1] && !check[x][y + 1])
			sum = dfs(x, y + 1, (sum * 10) + a[x][y]); // 가로로 종이를 이어붙여 넘김
		else
			return sum * 10 + a[x][y]; // 마지막 수 처리
	}
	if (xy[x][y] == 1) // 세로로 확인하는 경우
	{
		if (x + 1 < n && xy[x][y] == xy[x + 1][y]  && !check[x + 1][y])
			sum = dfs(x + 1, y, (sum * 10) + a[x][y]); // 세로로 종이를 이어붙여 넘김
		else
			return sum * 10 + a[x][y]; // 마지막 수 처리
	}
	return sum;
}

int makeSum() // 현재 각 조각의 합을 모두 구하는 함수
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (!check[i][j])
			{
				sum += dfs(i, j, 0);
			}
		}
	return sum;
}

void go(int index)
{
	if (index == m * n)
	{		
		memset(check, false, sizeof(check));
		ans.push_back(makeSum()); // 정답 후보
		return;
	}
	// ex) 0 ~ 15와 같이 인덱스를 돌며 모든 경우 확인
	xy[index / m][index % m] = 1; // 1을 넣는 경우
	go(index + 1);
	xy[index / m][index % m] = 0; // 0을 넣는 경우
	go(index + 1);

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			a[i][j] = str[j] - '0';
	}

	go(0);

	auto max = max_element(ans.begin(), ans.end());
	cout << * max << '\n'; // 최댓값 출력


}

```
