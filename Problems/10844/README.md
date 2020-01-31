# Problem 10844

## 쉬운 계단 수

### 문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

### 입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

### 출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/10844>

### 예제 입력 1
1

### 예제 출력 1
9

### solve first
- 점화식 d[i][j] = 길이가 i인 계단 수의 총 개수, 이전 수의 맨 마지막 수 = j
- (i != 1) => (0 <= j <= 9)  -> i = 1일때 예외처리
- j = 0 or j = 9 이면 다음에 올 수 있는 수는 1, 8 뿐
- 1 ~ 8은 j + 1, j - 1이 올 수 있음
	- ex) d[2][1] = sum(d[2 - 1][j])
	- ex) d[2][2] = sum(d[2 - 1][j]) * 2

- 첫 번째 코드
```C++

	#include<iostream>

	using namespace std;
	const long long mod = 1000000000;
	// 점화식 d[i][j] = 길이가 i인 계단 수의 총 개수, 이전 수의 맨 마지막 수 = j
	long long d[101][10];

	int main(void)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);

		int n;
		cin >> n;

		for (int j = 1; j <= 9; j++)
			d[1][j] = 1;

		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				if (j == 0 || j == 9) // 0 또는 9인 경우에는 다음에 올 수 있는 수는 1, 8뿐이므로 한번만 더해줌
					d[i][j] += d[i - 1][j];
				else // 1 ~ 8의 수 다음에는 j - 1, j + 1이 올 수 있으므로 두 배로 더해줌
				{
					d[i][j] += d[i - 1][j] * 2;
				}
				 d[i][j] %= mod;
			}
		}
		long long result = 0;
		for (int j = 1; j <= 9; j++)
			result += d[n][j];
		cout << result % mod << '\n';

	}


```
### solve second

- 위와 같이 하니 예제 입출력의 테스트케이스는 맞지만 틀렸다고 나옴.
- 생각해보니 단순히 j가 0이나 9일 때에 한 번만 더하고 두 번만 더하는 것이 잘못되었음
	- 정확히 0일때는 이전 수가 1인 경우 즉, d[i-1][j+1]인 경우를 더해줘야 하고
	- 9일때는 이전 수가 8 인 경우 즉, d[i-1][j-1]인 경우를 더해주어야 한다.
	- 또한 j가 1 ~ 8 인 경우에는 d[i-1][j-1]과 d[i-1][j+1] 모두를 더해주어야 한다.


### 코드 설명
```C++

#include<iostream>

using namespace std;
const long long mod = 1000000000;
// 점화식 d[i][j] = 길이가 i인 계단 수의 총 개수, 이전 수의 맨 마지막 수 = j
long long d[101][10];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int j = 1; j <= 9; j++)
		d[1][j] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			// d[i][j] = 0;
			if (j <= 8)
			{
				d[i][j] += d[i - 1][j + 1];
			}
			if (j >= 1)
			{
				d[i][j] += d[i - 1][j - 1];
			}
			 d[i][j] %= mod; // 미리 나머지로 바꿔주어야 정수 범위내에서 연산 가능
		}
	}
	long long result = 0;
	for (int j = 0; j <= 9; j++) // n의 모든 경우를 누적
		result += d[n][j];
	cout << result % mod << '\n';

}

```
