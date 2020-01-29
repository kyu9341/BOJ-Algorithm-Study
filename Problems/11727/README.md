# Problem 11727

## 2xn타일링2

### 문제
2×n 직사각형을 1x2와 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

### 출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/11726>

### 예제 입력 1
2

### 예제 출력 1
3

### 예제 입력 2
8

### 예제 출력 2
171

### 예제 입력 3
12

### 예제 출력 3
2731

### solve
- 2xn타일링 문제와 동일하게 진행되지만 2x2타일이 따로 존재한다는 점에서 다음과 같이 진행한다.
-  점화식 d[n] = 2xn 크기의 직사각형을 채우는 방법의 수
	- 2xn 크기의 직사각형에 타일을 추가로 붙이는 경우
	- 1. 2x1 타일을 하나 붙인다.
	- 2. 1x2 타일을 두 개 붙인다.
	- 3. 2x2 타일을 하나 붙인다.
- 2x(n-1)의 직사각형에 2x1타일을 하나 붙이는 경우의 수 + 2x(n-2)의 직사각형에 1x2타일을 두 개 붙이는 경우의 수 * 2
- d[n] = d[n - 1] + d[n - 2] * 2

### 코드 설명
```C++
#include<iostream>
// 2×n 직사각형을 1x2와 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
using namespace std;
int d[1001];
int tiling_bottom_up(int n);
int tiling_top_down(int n);

int main(void)
{
	int n;
	cin >> n;

	cout << tiling_top_down(n) <<'\n';
}

// 2xn 타일링 문제에서 d[n - 2]인 경우가 두배가 된 것.
int tiling_bottom_up(int n)
{
	d[1] = 1;
	d[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		if (d[i] > 0)
			continue;
		d[i] = d[i - 1] + d[i - 2] * 2; // d[n] = d[n - 1] + d[n - 2]\*2
		d[i] %= 10007;
	}
	return d[n];
}

int tiling_top_down(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;

	if (d[n] > 0)
		return d[n];
	else
	{
		d[n] = tiling_top_down(n - 1) + tiling_top_down(n - 2) * 2;
		d[n] %= 10007;
	}
	return d[n];
}
```
