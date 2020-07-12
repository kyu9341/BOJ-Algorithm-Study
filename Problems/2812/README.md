# Problem 2812

## 크게 만들기

### 문제
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)

둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

### 출력
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2812>

### 예제 입력 1
4 2
1924

### 예제 출력 1
94

### solve
- 프로그래머스에도 같은 문제가 있지만 시간 제한이 좀 널널했다.
- 하지만 같은 방식으로는 시간초과가 나기 때문에 deque를 이용하여 해결하였다. (스택을 사용해도 충분하지만 출력을 편하게 하기 위해)
- 덱이 비어있다면 원소를 넣고, 비어있지 않다면 덱의 가장 뒤의 원소와 현재 숫자를 비교한다.
- 현재 숫자가 더 작다면 그냥 맨 뒤에 원소를 추가하고, 현재 숫자가 더 크다면 덱의 맨 뒤의 원소를 계속해서 pop해준다. (cnt가 k보다 작을 때에 한에서)
- 전체를 모두 확인하고도 cnt가 k보다 작다면 그 차이 만큼 덱의 뒤에서 지워준다.
- 덱의 맨 앞에서부터 빼면서 ans에 누적하여 출력한다.

### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

int n, k;
string number;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	cin >> number;
	deque<int> dq;

	string ans = "";
	int cnt = 0;
	for (int i = 0; i < number.size(); i++) {
		int now = number[i] - '0';
		if (dq.empty()) {
			dq.push_back(now);
		}
		else { // 비어있지 않은 경우 덱의 가장 뒤의 원소가 현재 원소보다 작다면 pop한다.
			while (!dq.empty() && dq.back() < now && cnt < k) {
				dq.pop_back();
				cnt++;
			}
			dq.push_back(now);
		}

	}
	// 아직 지우지 못한 만큼 뒤에서 지워준다.
	while (cnt != k) {
		dq.pop_back();
		cnt++;
	}
	// 앞에서부터 빼면서 ans에 누적
	while (!dq.empty()) {
		ans += dq.front() + '0';
		dq.pop_front();
	}

	cout << ans << '\n';

}
```
