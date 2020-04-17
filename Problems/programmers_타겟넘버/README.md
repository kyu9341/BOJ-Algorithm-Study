# 프로그래머스 - 타겟 넘버

## 타겟 넘버

### 문제
n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.
```
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
```

사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

### 제한사항
주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
각 숫자는 1 이상 50 이하인 자연수입니다.
타겟 넘버는 1 이상 1000 이하인 자연수입니다.

### 입출력 예
numbers	target	return
[1, 1, 1, 1, 1]	3	5
입출력 예 설명
문제에 나온 예와 같습니다.

### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/43165>

### solve
- DFS를 재귀함수로 구현하여 해결하였다.
- index를 1씩 증가시키며 sum에 현재 index의 number를 더하는 경우, 빼는 경우를 구분하여 재귀를 수행한다.
- index가 배열의 크기와 같아지면(주어진 수를 모두 확인) 현재까지의 합이 타겟 넘버와 일치하는지 확인한다.
	- 일치한다면 1을 리턴하고 아니라면 0을 리턴한다.
- 반환되는 값을 모두 더하면 그것이 타겟 넘버를 만들 수 있는 모든 경우이다.

### 코드 설명
```C++
#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int target, int index, int sum, int count) {
	if (index == numbers.size()) {
		if (sum == target) {
			return 1; // 타겟 넘버를 만든 경우
		}
		else {
			return 0; // 만들지 못한 경우
		}
	}

	count = dfs(numbers, target, index + 1, sum + numbers[index], count) + dfs(numbers, target, index + 1, sum - numbers[index], count);

	return count;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	answer = dfs(numbers, target, 0, 0, 0);

	return answer;
}

```
