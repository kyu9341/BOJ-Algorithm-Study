# Problem 1748

## 수 이어 쓰기

### 문제
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

1234567891011121314151617181920212223...

이렇게 만들어진 새로운 수는 몇 자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N(1≤N≤100,000,000)이 주어진다.

### 출력
첫째 줄에 새로운 수의 자릿수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1748>

### 예제 입력 1
120

### 예제 출력 1
252

### solve
- 모든 수를 문자열로 바꾸어 계속 이어붙여 문자열의 길이를 구하는 방법도 있겠지만
	- n제한이 1억이기 때문에 불가능하다. 1초에 1억번 연산이 가능하다지만 수의 길이가 너무나 길기 때문에 더 오래걸린다.
- 다른 방법으로 해결해야 하는데, 중복이 되는 부분을 묶어서 처리하면 될 것 같다.
- n = 120이라고 하면
	- 한 자리 수 는 1~9 -> 9가지
	- 두 자리 수는 10 ~ 99 -> 99 - 10 + 1
	- 세 자리 수는 100 ~ 120 -> 120 - 100 + 1
- start에 각 자릿수의 시작 수를 넣고 10, 100, 1000 ...
- end에 각 자릿수의 마지막 수를 넣는다. 99, 999, 9999 ...
- 위 규칙에 따라 (end - start + 1)에 입력 수의 자릿수를 구해 곱해 누적하면 된다.
	- end가 n보다 커지면 end에 n을 넣어 남은 자릿수를 처리한다.

### 코드 설명
```C++
#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++)
	{	// start는 * 10씩 증가하므로 10, 100, 1000 .. (자릿수의 시작)
		int end = start * 10 - 1; // end는 99, 999, 9999 ... (자릿수의 마지막)
		if (end > n) // 입력 수보다 커지면
			end = n;
		ans += (long long)(end - start + 1) * len; // 자릿수의 개수에 자릿수를 곱함
	}
	cout << ans << '\n';
}

```
