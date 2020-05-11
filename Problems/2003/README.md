# Problem 2003

## 수들의 합 2

### 문제
N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N(1≤N≤10,000), M(1≤M≤300,000,000)이 주어진다. 다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 넘지 않는 자연수이다.

### 출력
첫째 줄에 경우의 수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2003>

### 예제 입력 1
4 2
1 1 1 1

### 예제 출력 1
3

### 예제 입력 2
10 5
1 2 3 4 2 5 3 1 1 2

### 예제 출력 2
3


### solve
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
const int MAX = 10000;
int a[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int end = 0;
	int sum = 0;
	int ans = 0;

	// start를 차례로 증가시키며 반복
	for (int start = 0; start < n; start++) {
		while (sum < m && end < n) {
			// end를 가능한 만큼 이동
			sum += a[end++];
		}
		// 부분 합이 m일 때, 카운트 증가
		if (sum == m) {
			ans++;
		}
		sum -= a[start];
	}

	cout << ans << '\n';


}
```
