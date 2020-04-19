# 프로그래머스 - 숫자 야구

## 숫자 야구

### 문제
숫자 야구 게임이란 2명이 서로가 생각한 숫자를 맞추는 게임입니다.

각자 서로 다른 1~9까지 3자리 임의의 숫자를 정한 뒤 서로에게 3자리의 숫자를 불러서 결과를 확인합니다. 그리고 그 결과를 토대로 상대가 정한 숫자를 예상한 뒤 맞힙니다.
```
* 숫자는 맞지만, 위치가 틀렸을 때는 볼
* 숫자와 위치가 모두 맞을 때는 스트라이크
* 숫자와 위치가 모두 틀렸을 때는 아웃
```

예를 들어, 아래의 경우가 있으면
```
A : 123
B : 1스트라이크 1볼.
A : 356
B : 1스트라이크 0볼.
A : 327
B : 2스트라이크 0볼.
A : 489
B : 0스트라이크 1볼.
```

이때 가능한 답은 324와 328 두 가지입니다.

질문한 세 자리의 수, 스트라이크의 수, 볼의 수를 담은 2차원 배열 baseball이 매개변수로 주어질 때, 가능한 답의 개수를 return 하도록 solution 함수를 작성해주세요.

### 제한사항
질문의 수는 1 이상 100 이하의 자연수입니다.
baseball의 각 행은 [세 자리의 수, 스트라이크의 수, 볼의 수] 를 담고 있습니다.
### 입출력 예
baseball	return
[[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]	2
### 입출력 예 설명
문제에 나온 예와 같습니다.

### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/42841>

### solve
- 1~9의 숫자를 중복 없이 사용하므로 가능한 경우는 최소 123 ~ 최대 987 이다.
- 123~987을 모두 확인하며 현재 숫자가 주어진 조건을 모두 만족한다면 answer를 1증가시키고 아니라면 넘어간다.
  - 먼저, 중복되는 숫자는 없으므로 같은 숫자가 있는 경우와 0이 들어가는 경우는 넘어간다.
  - 숫자를 모두 문자열로 변환하여 비교를 하며 현재 숫자가 이번 경우의 스트라이크와 볼의 수를 만족한다면 계속 확인하고 하나라도 만족하지 않는다면 다음 숫자로 넘어간다.
  - 모든 조건을 만족하면 answer를 1증가시킨다.


### 코드 설명
```C++
#include <string>
#include <vector>
#include <set>
#include <string>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	// 1~9의 숫자이므로 가능한 모든 범위는 123 ~ 987
	for (int i = 123; i <= 987; i++) {
		string cur = to_string(i);
		// 모두 서로 다른 숫자이므로 같은 숫자가 있는 경우는 확인 안함
		if (cur[0] == cur[1] || cur[1] == cur[2] || cur[0] == cur[2]) continue;
		// 0이 있는 경우는 불가능
		if (cur[0] == '0' || cur[1] == '0' || cur[2] == '0') continue;

		// 조건을 만족하는지 확인할 변수
		bool check = true;

		for (int j = 0; j < baseball.size(); j++) {
			string num = to_string(baseball[j][0]);
			int s = 0; // 스트라이크
			int b = 0; // 볼

			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					// 스트라이크인 경우
					if (k == l && num[k] == cur[l]) s++;
					// 볼인 경우
					else if (num[k] == cur[l]) b++;
				}
			}
			// 현재 조건을 만족하는지 확인
			if (s != baseball[j][1] || b != baseball[j][2]) {
				check = false;
				break;
			}

		}

		if (check) answer++;
	}

	return answer;
}

```
