# Problem 1300

## k번째 수

### 문제
세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.

배열 A와 B의 인덱스는 1부터 시작한다.

### 입력
첫째 줄에 배열의 크기 N이 주어진다. N은 10^5보다 작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(10^9, N2)보다 작거나 같은 자연수이다.

### 출력
B[k]를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1300>

### 예제 입력 1
3
7

### 예제 출력 1
6

### solve
- B의 현재 원소의 인덱스를 구해 k와 비교하며 이분 탐색을 수행한다.
- 인덱스를 구하는 방법은 현재 원소보다 작거나 같은 원소의 개수를 구하면 된다.
	- 예를 들어, 5 * 5 행렬에서 8보다 작거나 같은 수의 개수를 구한다면

**1 2 3 4 5**
**2 4 6 8** 10
**3 6** 9 12 15
**4 8** 12 16 20
**5** 10 15 20 25

- a[i][j] = i * j 이므로 위와 같이 구할 수 있다.
	- 즉, 8을 1부터 n까지 각 행으로 나누었을 때의 몫이 그 행에서 8보다 작거나 같은 수의 개수가 된다.
	- 이 때, 1행과 같이 몫이 8보다 작다면 n이 8보다 작거나 같은 수의 개수가 된다.
	- 또한 8로 나누어 떨어지는 행에는 8이 존재한다.
- 따라서 위와 같이 8보다 작거나 같은 수의 개수를 구하면 14가 되고, 이것이 8의 인덱스가 된다.(1부터 시작)


### 코드 설명
```C++
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<climits>

using namespace std;
long long n, k;

long long go(long long mid) // mid의 인덱스를 구하는 함수
{
	long long cnt = 0;
	for (long long i = 1; i <= n; i++)
	{ // 현재 원소(mid)보다 작거나 같은 수의 개수를 count
		cnt += min(n, mid / i);
	}
	return cnt; // mid의 인덱스
}

int main(void)
{
	cin >> n >> k;

	long long left = 1;
	long long right = n * n;
	long long ans = 1;
	while (left <= right)
	{
		long long mid = (left + right) / 2; // 현재 원소

		if (go(mid) >= k) // 현재 원소의 인덱스가 더 크다면
		{
			ans = mid;
			right = mid - 1; // 현재 원소를 감소시켜 확인
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans << '\n';
}

```
