# Problem 1676

## 팩토리얼 0의 개수

### 문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

### 출력
첫째 줄에 구한 0의 개수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1676>

### 예제 입력 1
10

### 예제 출력 1
2

### solve
- 팩토리얼의 0의 개수는 n!을 소인수분해하여 나온 2와 5의 개수로 얻을 수 있다.
	- (뒤에서부터 연속으로 등장하는 0의 개수이므로)
- n!에서는 2의 개수가 항상 5의 개수보다 많으므로 5의 개수만 세어준다.

### 코드 설명
```C++
#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// 팩토리얼의 0의 개수는 n!을 소인수분해하여 나온 2와 5의 개수로 얻을 수 있다.
	// n!에서는 2의 개수가 항상 5의 개수보다 많으므로 5의 개수만 세어준다.
	int n;
	cin >> n;
	int count = 0;

	for (int i = n; i > 0; i--)
	{
		int tmp = i;
		while (tmp % 5 == 0) // 5의 개수 count
		{
			tmp /= 5; // 5를 하나 이상 인자로 가지는 수 처리
			count++;
		}
	}
	cout << count << '\n';
}
```
