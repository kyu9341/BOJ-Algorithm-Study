# Problem 1790

## 수 이어 쓰기 2

### 문제
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

> 1234567891011121314151617181920212223...

이렇게 만들어진 새로운 수에서, 앞에서 k번째 자리 숫자가 어떤 숫자인지 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N(1 ≤ N ≤ 100,000,000)과,  k(1 ≤ k ≤ 1,000,000,000)가 주어진다. N과 k 사이에는 공백이 하나 이상 있다.

### 출력
첫째 줄에 앞에서 k번째 자리 숫자를 출력한다. 수의 길이가 k보다 작아서 k번째 자리 숫자가 없는 경우는 -1을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1790>

### 예제 입력 1
20 23

### 예제 출력 1
6

### solve
- 1부터 N까지의 수를 이어 써서 만든 수의 길이를 구하는 함수 calc를 만든다.
- 먼저 n까지 이어 쓴 수의 길이가 k보다 작으면 불가능하므로 예외처리를 한다.
- 이분 탐색을 통해 어떤 수까지를 이어 써야 k번째 수가 나오는지 확인한다.
- 그 수(ans)를 찾으면 k번째 수를 구하기 위해 ans의 길이를 구해 calc(ans) - k를 ans의 길이에서 빼고 인덱스를 구한다.


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>
using namespace std;

long long calc(int n) // n까지의 수를 모두 이어 썼을 때, 그 수의 길이
{
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++)
	{ // start : 자리수의 첫 수, len : 길이
		int end = start * 10 - 1;
		if (end >= n)
			ans += (long)((n - start + 1) * len);
		else
			ans += (long)((end - start + 1) * len); // 현재 자리수까지의 길이 누적
	}
	return ans;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	if (calc(n) < k) // n까지 이어 쓴 수의 길이가 k보다 작으면 불가능
	{
		cout << -1 << '\n';
		return 0;
	}
	int left = 1;
	int right = n;
	int ans = 0;
	while (left <= right) // 이분 탐색
	{ // 어떤 수까지를 이어 써야 k번째 수가 나오는지 확인
		int mid = (left + right) / 2;
		long long len = calc(mid);
		if (k > len)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}
	string s = to_string(ans);
	long long l = calc(ans);
	// l - k를 구해서 마지막 수의 길이에서 뺀다.
	cout << s[s.size() - (l - k) - 1] << '\n';
}

```
