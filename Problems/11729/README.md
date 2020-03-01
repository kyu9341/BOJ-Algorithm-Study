# Problem 11729

## 하노이 탑 이동 순서

### 문제
세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다. 이제 수도승들이 다음 규칙에 따라 첫 번째 장대에서 세 번째 장대로 옮기려 한다.

1. 한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
2. 쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.

이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 최소가 되어야 한다.

아래 그림은 원판이 5개인 경우의 예시이다.

![hanoi](https://kyu9341.github.io/img/hanoi.png)

### 입력
첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.

### 출력
첫째 줄에 옮긴 횟수 K를 출력한다.

두 번째 줄부터 수행 과정을 출력한다. 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.

### 문제 링크
<https://www.acmicpc.net/problem/11729>

### 예제 입력 1
3

### 예제 출력 1
7
1 3
1 2
3 2
1 3
2 1
2 3
1 3

### solve
- 분할 정복으로 재귀 함수를 사용한다.
- 제인 큰 원반을 제외한 n - 1개의 원반을 기둥 1에서 기둥 2로 이동시킨다.
- 제일 큰 원반 한개를 기둥 1에서 기둥 3으로 이동시킨다.
- 기둥 2로 옮긴 n - 1개의 원반을 다시 기둥 3으로 이동시킨다.


### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

void go(int n, int from, int by, int to) // n개의 원판을 from에서 by를 거쳐 to로 이동시킴
{
	if (n == 1) cout << from << ' ' << to << '\n';
	else
	{
		go(n - 1, from, to, by); // n - 1개의 원반을 기둥 3을 거쳐 2로 옮긴다.
		cout << from << ' ' << to << '\n'; // 기둥 1에서 1개의 원반을 기둥 3으로 옮긴다.
		go(n - 1, by, from, to); // 기둥 2에서 n - 1개의 원반을 기둥 3으로 옮긴다.
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // 횟수는 2^n - 1 번

	go(n, 1, 2, 3);
}

```
