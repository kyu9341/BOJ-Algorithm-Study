# Problem 9095

## 1, 2, 3 더하기

### 문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

- 1+1+1+1
- 1+1+2
- 1+2+1
- 2+1+1
- 2+2
- 1+3
- 3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

### 출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/9095>

### 예제 입력 1
3
4
7
10

### 예제 출력 1
7
44
274

### solve
- 점화식 d[n] = n을 1, 2, 3의 합으로 나타내는 방법의 수
- o + o + o + ... + **o** = n  --> **o** 의 자리에 올 수 있는 수 : 1, 2, 3
	- [  합 : n - 1    ] + 1 = n;
	- [  합 : n - 2    ] + 2 = n;
	- [  합 : n - 3    ] + 3 = n;
- d[n] = d[n - 1] + d[n - 2] + d[n - 3]
	- d[0] = 1 // 공집합, 모든 숫자를 0개씩 사용하는 경우 1
	- d[1] = 1 // 1
	- d[2] = 2 // 1+1, 2


### 코드 설명
- 동적 계획법
```C++
#include<iostream>

using namespace std;
int sum123_top_down(int n);
int sum123_bottom_up(int n);

int d[11]; // n < 11, d[n] = n을 1, 2, 3의 합으로 나타내는 방법의 수

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	cin >> t; // testcase

	while (t--)
	{
		cin >> n;
		cout << sum123_top_down(n) << '\n';
	}
}

int sum123_top_down(int n)
{
	if (n <= 1) // d[0] = 1(공집합, 모든 숫자를 0개씩 사용), d[1] = 1
		return 1;
	if (n == 2) // 1 + 1, 2
		return 2;
	if (d[n] > 0) // 메모되어있으면 리턴
		return d[n];
	else
	{		// d[n] = d[n - 1] + d[n - 2] + d[n - 3]
		d[n] = sum123_top_down(n - 1) + sum123_top_down(n - 2) + sum123_top_down(n - 3);
	}
	return d[n];
}

int sum123_bottom_up(int n)
{
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		if (d[i] > 0)
			continue;
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
	return d[n];
}
```

- 부르트 포스(재귀)
```cpp
#include<iostream>

using namespace std;
int go(int sum, int goal)
{
	if (sum > goal) return 0;	// 1, 2, 3으로 원하는 수를 만들 수 없는 경우
	if (sum == goal) return 1;  // 만든 경우
	int count = 0;
	for (int i = 1; i <= 3; i++)
		count += go(sum + i, goal);
	return count;
}
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << go(0, n) << '\n';
	}
}
```
