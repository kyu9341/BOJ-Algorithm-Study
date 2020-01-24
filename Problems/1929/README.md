# Problem 1929

## 소수 구하기

### 문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

### 입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)

### 출력
계산 결과를 소숫점 둘째 자리까지 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1929>

### 예제 입력 1
3 16

### 예제 출력 1
3
5
7
11
13


### solve
- 에라토스테네스의 체
	- 2부터 n까지의 모든 수를 써놓는다.
	- 아직 지워지지 않은 수 중에서 가장 작은 수를 찾는다.
	- 그 수는 소수이다.
	- 이제 그 수의 배수를 모두 지운다.

### 코드 설명
```C++
#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool check[1000001] = { false }; // 각 숫자의 소수 여부를 체크할 bool배열
	int m, n; // 소수 범위 (1 ≤ M ≤ N ≤ 1,000,000)
	cin >> m >> n;
	check[1] = true; // 1은 소수가 아님
	//  에라토스테네스의 체
	for (int i = 2; i*i <= n; i++) // i^2이 n을 넘어가면 i의 배수는 이미 모두 지워짐
	{
		if(!check[i])
			for (int j = i; j*i <= n; j++) // i*i이상의 i의 배수를 모두 지워줌
			{
				if (i * j > 1000000)
					break;
				check[i * j] = true; // 소수가 아니면 true

			}
	}
	for (int i = m; i <= n; i++)
	{
		if (!check[i])
			cout << i << '\n';
	}

}
```
