# Problem 1074

## Z

### 문제
한수는 2차원 배열 (항상 2^N * 2^N 크기이다)을 Z모양으로 탐색하려고 한다. 예를 들어, 2*2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.

만약, 2차원 배열의 크기가 2^N * 2^N라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 4등분 한 후에 (크기가 같은 2^(N-1)로) 재귀적으로 순서대로 방문한다.

다음 예는 2^2 * 2^2 크기의 배열을 방문한 순서이다.

N이 주어졌을 때, (r, c)를 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

다음 그림은 N=3일 때의 예이다.

### 입력
첫째 줄에 N r c가 주어진다. N은 15보다 작거나 같은 자연수이고, r과 c는 0보다 크거나 같고, 2^N-1보다 작거나 같은 정수이다

### 출력
첫째 줄에 문제의 정답을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1074>

### 예제 입력 1
2 3 1

### 예제 출력 1
11

### 예제 입력 2
3 7 7

### 예제 출력 2
63

### solve
- 재귀함수로 분할정복을 통해 해결하였다.
- n은 2^n으로 변경하여 인자로 넘겨준다.
- 크기가 n * n인 2차원 배열을 4분할하여 2행 2열이 되면 지그재그로 몇 번째 방문인지 카운트한다.
- i가 r , j가 c가 되면 그 때의 ans를 출력하고 리턴한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<utility>


using namespace std;
int r, c;
int ans = 0;

void zigzag(int x, int y, int n) // 지그재그로 방문하는 함수
{
	if (n == 2) // 2행 2열이 된 경우
	{
		for(int i = x; i < x + n; i++)
			for (int j = y; j < y + n; j++)
			{
				if (i == r && j == c) // r, c에 도착하면 출력 후 리턴
				{
					cout << ans << '\n';
					return;
				}
				ans++; // 1씩 증가
			}
		return;
	}

	int m = n / 2;
	for (int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			zigzag(x + m * i, y + m * j, m); // n / 2씩 건너뛰며 재귀

}

int main(void)
{
	int n;
	cin >> n >> r >> c;
	n = (1 << n);
	zigzag(0, 0, n); // 0, 0 부터 탐색 n은 2^n
}

```
