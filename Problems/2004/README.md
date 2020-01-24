# Problem 2004

## 조합 0의 개수

### 문제
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

### 입력
첫째 줄에 정수 n, m(0≤m≤n≤2,000,000,000, n!=0)이 들어온다.

### 출력
첫째 줄에 0의 개수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2004>

### 예제 입력 1
25 12

### 예제 출력 1
2

### solve
- 팩토리얼의 0의 개수는 n!을 소인수분해하여 나온 2와 5의 개수로 얻을 수 있다.
	- (뒤에서부터 연속으로 등장하는 0의 개수이므로)
- nCm = n! / (n-m)!\*m!
- 조합의 0의 개수는 n!의 0의 개수에서 (n-m)!의 0의 개수와 m!의 0의 개수를 빼주면 된다.
- 조합의 0의 개수는 항상 5의 개수가 더 많지 않을 수 있으므로 2와 5의 개수 중 더 작은 값을 구하면 된다.
- 범위가 매우 크기 때문에 int형이 아닌 long long 형을 사용한다. (int형 사용시 런타임에러)
- 이때 2와 5의 개수를 구하는 방법은 팩토리얼의 0의 개수를 구할 때와는 다르게 구한다.
	- 최대 2,000,000,000의 수가 들어오기 때문에 시간 초과가 발생할 수 있음
	- n!의 i의 개수를 구한다고 한다면
	- 먼저 count에 n / i를 더한다.
	- n을 i로 나누어도 i^2의 배수들은 i가 남아있기 때문에 count에 n / i^2 을 더한다.
	- i^3의 배수같은 경우는 i^2으로 나누어도 i가 남아있기 때문에 count에 n / i^3을 더한다.
	- 위의 과정을 반복한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>

using namespace std;

pair<long long, long long> zeros(long long n)
{
	long long two = 0;
	long long five = 0;
	for (long long i = 5; i <= n; i *= 5) // 5의 개수 카운트
		five += n / i;
	for (long long i = 2; i <= n; i *= 2) // 2의 개수 카운트
		two += n / i;
	return {two, five};
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;

	pair<long long, long long> resM, resN, resNM;
	long long two = 0, five = 0;
	resM = zeros(m);
	resN = zeros(n);
	resNM = zeros(n - m);

	two = resN.first - resM.first - resNM.first; // n의 2의 개수에서 m과 (n-m)의 2의 개수를 빼줌
	five = resN.second - resM.second - resNM.second;  // n의 5의 개수에서 m과 (n-m)의 5의 개수를 빼줌

	cout << min(two, five) << '\n';
	return 0;
}


```
