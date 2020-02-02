# Problem 2133

## 타일 채우기

### 문제
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

### 입력
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

### 출력
첫째 줄에 경우의 수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2133>

### 예제 입력 1
2

### 예제 출력 1
3

### solve
- d[n] = d[n - 2] * 3 + d[n - 4] * 2 + d[n - 6] * 2 ... (n - 2i) >= 0


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
using namespace std;
int d[31]; // d[n] = d[n - 2] * 3 + d[n - 4] * 2 + d[n - 6] * 2 ... (n - 2i) >= 0
int main(void)
{
	int n;
	cin >> n;

	d[0] = 1; // 초기값 지정 (마지막 +2 역할)
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
		{
			d[i] += d[j] * 2;
		}
	}
	cout << d[n] << '\n';

}
```
