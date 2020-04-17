# 프로그래머스 - 소수 찾기

## 소수 찾기

### 문제
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

### 제한사항
- numbers는 길이 1 이상 7 이하인 문자열입니다.
- numbers는 0~9까지 숫자만으로 이루어져 있습니다.
- 013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
### 입출력 예
numbers	return
17	3
011	2
### 입출력 예 설명
- 예제 #1
	- [1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

- 예제 #2
	- [0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.

### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/42839>

### solve
- 에라토스테네스의 체를 이용하여 소수를 구하고 재귀로 순열을 구현하여 해결하였다.
- numbers문자열에 각 수를 하나씩 추가해보며 재귀를 수행하고 현재 문자열이 빈 문자열이 아니고 중복되지 않은 경우 카운트한다.
	- 이때, 이미 사용한 인덱스의 수를 사용하지 않도록 check배열에 기록한다.
- 또한 같은 수가 두 번 카운트되면 안되므로 visit배열을 사용하여 한 번 확인한 수는 다시 확인하지 않는다.

### 코드 설명
```C++
#include <string>
#include <vector>
#include<iostream>

using namespace std;
const int MAX = 10000000;
bool check[8];
bool prime[MAX];
bool visit[MAX];
int cnt = 0;

void go(int index, string numbers, string cur) {
	// 현재 문자열이 빈 문자열이 아니고 중복되지 않은 경우
	if (cur != "" && !visit[stoi(cur)]) {
		int num = stoi(cur);
		if (!visit[num]) {
			visit[num] = true; // 방문 처리
			if (!prime[num])cnt++; // 소수인 경우 카운트
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (check[i]) continue; // 이미 사용한 수이면 통과
		check[i] = true;
		go(index + 1, numbers, cur + numbers[i]);
		check[i] = false;


	}

}



int solution(string numbers) {
	int answer = 0;
	prime[0] = true;
	prime[1] = true;
	// 에라토스테네스의 체
	for (int i = 2; i * i < MAX; i++) {
		if (prime[i] == false) {
			for (int j = i + i; j < MAX; j += i) {
				prime[j] = true;
			}
		}
	}

	go(0, numbers, "");
	answer = cnt;
	return answer;
}

```
