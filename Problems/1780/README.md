# Problem 1780

## 종이의 개수

### 문제
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다. 우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

### 입력
첫째 줄에 N(1≤N≤3^7, N은 3^k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

### 출력
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1780>

### 예제 입력 1
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1

### 예제 출력 1
10
12
11

### solve
- 분할 정복으로 재귀 함수를 통해 해결하였다.
- 종이의 전체를 확인하고 모두 같지 않다면 9개로 분할하여 다시 확인하는 것을 반복한다.
- (x, y) : 종이의 시작점(가장왼쪽 가장위), n : 종이의 크기 를 인자로 가지는 함수로
	- 모든 칸이 같은 수라면 해당 수의 개수를 +1하고 리턴,
	- 같지 않다면 (x, y)를 (x + n, y + n)까지 n / 3 만큼씩 증가시키며 재귀를 수행한다.


### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
int a[2187][2187];
int cnt[3];

bool same(int x, int y, int n) // 현재 종이의 모든 칸이 같은지 확인하는 함수
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (a[x][y] != a[i][j])
			{
				return false;
			}
		}
	return true;
}

void div(int x, int y, int n) // (x, y) : 종이의 시작점(가장왼쪽 가장위), n : 종이의 크기
{
	if (same(x, y, n)) // 모든 칸이 같은 경우
	{
		if (a[x][y] == 0)
			cnt[0]++;
		else if (a[x][y] == 1)
			cnt[1]++;
		else
			cnt[2]++;
		return;
	}
	else // 모든 같이 같지 않으면 다시 분할하여 확인
	{
		for (int i = x; i < x + n; i += n / 3) // 전체를 9분할하여 모두 확인
			for (int j = y; j < y + n; j += n / 3)
			{
				div(i, j, n / 3);
			}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	div(0, 0, n);

	cout << cnt[2] << '\n';
	cout << cnt[0] << '\n';
	cout << cnt[1] << '\n';
}

```
