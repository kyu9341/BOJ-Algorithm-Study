# Problem 5052

## 전화번호 목록

### 문제
전화번호 목록이 주어진다. 이때, 이 목록이 일관성이 있는지 없는지를 구하는 프로그램을 작성하시오.

전화번호 목록이 일관성을 유지하려면, 한 번호가 다른 번호의 접두어인 경우가 없어야 한다.

예를 들어, 전화번호 목록이 아래와 같은 경우를 생각해보자

- 긴급전화: 911
- 상근: 97 625 999
- 선영: 91 12 54 26
이 경우에 선영이에게 전화를 걸 수 있는 방법이 없다. 전화기를 들고 선영이 번호의 처음 세 자리를 누르는 순간 바로 긴급전화가 걸리기 때문이다. 따라서, 이 목록은 일관성이 없는 목록이다.

### 입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (1 ≤ t ≤ 50) 각 테스트 케이스의 첫째 줄에는 전화번호의 수 n이 주어진다. (1 ≤ n ≤ 10000) 다음 n개의 줄에는 목록에 포함되어 있는 전화번호가 하나씩 주어진다. 전화번호의 길이는 길어야 10자리이며, 목록에 있는 두 전화번호가 같은 경우는 없다.

### 출력
각 테스트 케이스에 대해서, 일관성 있는 목록인 경우에는 YES, 아닌 경우에는 NO를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/5052>

### 예제 입력 1
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346

### 예제 출력 1
NO
YES

### solve
- 프로그래머스의 전화번호 목록 문제와 똑같은 문제이다.
- 문자열을 오름차순 정렬한다.
	- 예제를 오름차순 정렬하면 다음과 같다.
		- ex1) 119, 1195524421, 97674223
- 다른 번호의 접두사가 되는 번호가 있다면 반드시 접두가가 되는 번호 뒤에 접두사로 가지는 번호가 오게 된다.
- 접두사가 되는 경우가 하나라도 있는지 유무만 판별하는 문제이므로
	- 정렬된 상태에서 바로 다음 문자열이 현재 문자열로 시작하는 경우가 있는지 판별한다.


### 코드 설명
```C++
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cin.ignore();
		vector<string> numbers(n);
		for (int i = 0; i < n; i++)
			cin >> numbers[i];
		// 문자열을 오름차순 정렬
		sort(numbers.begin(), numbers.end());
		bool check = false;
		for (int i = 0; i < n - 1; i++) {
			// 정렬된 상태이므로 바로 다음 문자열이 현재 문자열로 시작하는지 확인
			if (numbers[i].size() <= numbers[i + 1].size()) {
				if (numbers[i] == numbers[i + 1].substr(0, numbers[i].size())) {
					cout << "NO" << '\n';
					check = true;
					break;
				}
			}
		}
		if(!check) cout << "YES" << '\n';
	}
}
```
