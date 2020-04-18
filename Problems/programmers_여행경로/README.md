# 프로그래머스 - 여행경로

## 여행경로

### 문제
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 ICN 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

### 제한사항
- 모든 공항은 알파벳 대문자 3글자로 이루어집니다.
- 주어진 공항 수는 3개 이상 10,000개 이하입니다.
- tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
- 주어진 항공권은 모두 사용해야 합니다.
- 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
- 모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.

### 입출력 예
tickets	return
[[ICN, JFK], [HND, IAD], [JFK, HND]]	[ICN, JFK, HND, IAD]
[[ICN, SFO], [ICN, ATL], [SFO, ATL], [ATL, ICN], [ATL,SFO]]	[ICN, ATL, ICN, SFO, ATL, SFO]

### 입출력 예 설명
- 예제 #1
  - [ICN, JFK, HND, IAD] 순으로 방문할 수 있습니다.
- 예제 #2
  - [ICN, SFO, ATL, ICN, ATL, SFO] 순으로 방문할 수도 있지만 [ICN, ATL, ICN, SFO, ATL, SFO] 가 알파벳 순으로 앞섭니다.

### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/43164>

### solve
- dfs를 사용하여 tickets배열을 매번 모두 탐색하며 다음 출발지가 현재 위치와 일치하는 아직 사용하지 않은 티켓이 있는지 확인한다.
  - 조건을 만족하는 티켓이 있다면 티켓을 사용처리(visit[i] = true) 하고 재귀를 수행한다.
- 모든 티켓을 사용한 경우 재귀를 종료한다.
- 시작 지점은 항상 "ICN"이다.
- 방문 순서는 알파벳 순으로 앞서는 경우를 출력해야 하므로 dfs수행 전에 tickets벡터를 먼저 정렬한다.

### 코드 설명
```C++
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 10000;
bool visit[MAX + 1];

bool dfs(string node, vector<vector<string>>& tickets, vector<string>& answer, int index) {
	answer.push_back(node);
	if (index == tickets.size()) { // 모든 티켓을 사용한 경우
		return true;
	}

	for (int i = 0; i < tickets.size(); i++) {
		string next = tickets[i][1];
		string now = tickets[i][0];
		// 다음 출발지가 현재 위치와 일치하는 아직 사용하지 않은 티켓이 있는지 확인
		if (now == node && visit[i] == false) {
			visit[i] = true;
			if (dfs(next, tickets, answer, index + 1)) return true;
			visit[i] = false;
		}
	}
	answer.pop_back();

	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end());
	dfs("ICN", tickets, answer, 0);

	return answer;
}

```
