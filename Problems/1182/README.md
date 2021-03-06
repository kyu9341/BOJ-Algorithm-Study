# Problem 1182

## 부분수열의 합

### 문제
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

### 출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1182>

### 예제 입력 1
5 0

-7 -3 -2 5 8

### 예제 출력 1
1

### solve
- 비트마스크를 사용하여 해결한다.
- n개로 이루어진 수열이므로 0 ~ (n - 1)까지 확인하면 된다. [i < (1 << n)]
	- 아무것도 더하지 않는 경우는 제외하므로 1부터 확인한다.
- 1, 10, 11, 100, ... , 11111 까지 &연산을 통해 입력된 배열의 0 ~ n까지의 모든 인덱스를 확인한다.
	- if(i & (1 << k)) -> ex) i가 101 인경우 1, 100 만 통과
- n개의 수열 중 하나 이상의 원소를 뽑는 모든 경우를 탐색하여 합을 계산하여 s와 일치하는 경우 count한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int a[21];
int main(void)
{
	int n, s;
	int sum;

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	// n개로 이루어진 수열 -> 0 ~ (n - 1) 까지 확인
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) // 비트마스크 사용
	{
		sum = 0;
		for (int k = 0; k < n; k++) // 모든 경우를 확인
		{
			if (i & (1 << k)) // ex) i가 101 인경우 1, 100 만 통과
				sum += a[k]; // 모든 부분수열의 합을 구함
		}
		if (s == sum)
			ans++;
	}
	cout << ans << '\n';
}

```
