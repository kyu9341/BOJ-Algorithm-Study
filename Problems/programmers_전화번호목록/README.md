# 프로그래머스 - 전화번호 목록

## 전화번호 목록

### 문제
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

### 제한 사항
phone_book의 길이는 1 이상 1,000,000 이하입니다.
각 전화번호의 길이는 1 이상 20 이하입니다.

### 입출력 예제
phone_book	return
[119, 97674223, 1195524421]	false
[123,456,789]	true
[12,123,1235,567,88]	false

### 입출력 예 설명
- 입출력 예 #1
	- 앞에서 설명한 예와 같습니다.

- 입출력 예 #2
	- 한 번호가 다른 번호의 접두사인 경우가 없으므로, 답은 true입니다.

- 입출력 예 #3
	- 첫 번째 전화번호, “12”가 두 번째 전화번호 “123”의 접두사입니다. 따라서 답은 false입니다.

### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/42577>

### solve
- 문자열을 오름차순 정렬한다.
	- 1번 예제를 오름차순 정렬하면 다음과 같다.
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

bool solution(vector<string> phone_book) {
	bool answer = true;
	// 문자열 정렬
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++) {
		// 정렬된 상태이므로 바로 다음 문자열이 현재 문자열로 시작하는지 확인
		if (phone_book[i].size() <= phone_book[i + 1].size()) {
			if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
				answer = false;
				break;
			}
		}
	}
	return answer;
}
```
