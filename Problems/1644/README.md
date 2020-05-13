# Problem 1644

## 소수의 연속합

### 문제
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.

- 3 : 3 (한 가지)
- 41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
- 53 : 5+7+11+13+17 = 53 (두 가지)
하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.

자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)

### 출력
첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1644>

### 예제 입력 1
20

### 예제 출력 1
0

### 예제 입력 2
3

### 예제 출력 2
1


### solve
- 에라토스테네스의 체로 n이하의 소수로 이루어진 벡터를 만든다.
- 소수들의 벡터에서 투포인터 알고리즘으로 합이 n이되는 경우의 수를 모두 구한다.

- **[투 포인터 알고리즘]**
- 리스트에 순차적으로 접근해야 할 때 두 개의 점을 이용해 위치를 기록하면서 처리하는 기법

1. 시작점(start)와 끝점(end)이 첫 번째 원소의 인덱스(0)을 가리키도록 한다.
2. 현재 부분 합이 M과 같다면, 카운트한다.
3. 현재 부분 합이 M보다 작거나 같다면, end를 1증가시킨다.
4. 현재 부분 합이 M보다 크다면, start를 1증가시킨다.
5. 모든 경우를 확인할 때까지 2번부터 4번까지의 과정을 반복한다.


### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
const int MAX = 4000000;
vector<int> prime;
bool check[MAX + 1]; // 소수이면 false

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	check[1] = true;
	// 에라토스테네스의 체
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			prime.push_back(i); // 소수들만 벡터에 추가
			for (int j = i + i; j <= n; j += i) {
				check[j] = true; // 소수가 아니면 true
			}
		}
	}

	int end = 0;
	int sum = 0;
	int ans = 0;
	// 소수의 벡터에서 투포인터 알고리즘
	for (int start = 0; start < prime.size(); start++) {
		while (end < prime.size() && sum < n) {
			sum += prime[end++];
		}
		if (sum == n) ans++;
		sum -= prime[start];
	}

	cout << ans << '\n';
}
```
