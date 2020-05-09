# 프로그래머스 - 불량 사용자

## 불량 사용자

### 문제
개발팀 내에서 이벤트 개발을 담당하고 있는 무지는 최근 진행된 카카오이모티콘 이벤트에 비정상적인 방법으로 당첨을 시도한 응모자들을 발견하였습니다. 이런 응모자들을 따로 모아 불량 사용자라는 이름으로 목록을 만들어서 당첨 처리 시 제외하도록 이벤트 당첨자 담당자인 프로도 에게 전달하려고 합니다. 이 때 개인정보 보호을 위해 사용자 아이디 중 일부 문자를 '\*' 문자로 가려서 전달했습니다. 가리고자 하는 문자 하나에 '\*' 문자 하나를 사용하였고 아이디 당 최소 하나 이상의 '\*' 문자를 사용하였습니다.
무지와 프로도는 불량 사용자 목록에 매핑된 응모자 아이디를 제재 아이디 라고 부르기로 하였습니다.

예를 들어, 이벤트에 응모한 전체 사용자 아이디 목록이 다음과 같다면

응모자 아이디
frodo
fradi
crodo
abc123
frodoc
다음과 같이 불량 사용자 아이디 목록이 전달된 경우,

불량 사용자
fr*d*
abc1**
불량 사용자에 매핑되어 당첨에서 제외되어야 야 할 제재 아이디 목록은 다음과 같이 두 가지 경우가 있을 수 있습니다.

제재 아이디
frodo
abc123
제재 아이디
fradi
abc123
이벤트 응모자 아이디 목록이 담긴 배열 user_id와 불량 사용자 아이디 목록이 담긴 배열 banned_id가 매개변수로 주어질 때, 당첨에서 제외되어야 할 제재 아이디 목록은 몇가지 경우의 수가 가능한 지 return 하도록 solution 함수를 완성해주세요.

### [제한사항]
- user_id 배열의 크기는 1 이상 8 이하입니다.
- user_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
	- 응모한 사용자 아이디들은 서로 중복되지 않습니다.
	- 응모한 사용자 아이디는 알파벳 소문자와 숫자로만으로 구성되어 있습니다.
- banned_id 배열의 크기는 1 이상 user_id 배열의 크기 이하입니다.
- banned_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
	- 불량 사용자 아이디는 알파벳 소문자와 숫자, 가리기 위한 문자 '\*' 로만 이루어져 있습니다.
	- 불량 사용자 아이디는 '\*' 문자를 하나 이상 포함하고 있습니다.
	- 불량 사용자 아이디 하나는 응모자 아이디 중 하나에 해당하고 같은 응모자 아이디가 중복해서 제재 아이디 목록에 들어가는 경우는 없습니다.
- 제재 아이디 목록들을 구했을 때 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리하여 하나로 세면 됩니다.


### 입출력 예
user_id	banned_id	result
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["fr*d*", "abc1**"]	2
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["\*rodo", "\*rodo", "******"]	2
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["fr*d*", "\*rodo", "******", "******"]	3

### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/64064>

### solve
- 불량 사용자 아이디에 가능한 유저 후보를 cand벡터의 해당하는 인덱스에 담는다.
- 이후 가능한 후보들 중에서 중복되지 않는 경우를 구한다.
	- 가능한 경우에 res라는 set에 insert하고 재귀를 수행하여 가능한 제제 아이디 목록을 구한다.
	- set은 자동으로 정렬이 되므로 res를 s라는 set<string>을 담는 set에 넣어 중복인 경우가 없도록 한다.
- s의 size를 answer에 넣어 반환한다.

### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<map>
#include<set>

using namespace std;
vector<string> cand[8];
map<string, bool> m;
set<set<string>> s;

// 가능한 후보들 중에서 중복되지 않는 경우를 구한다.
void go(int index, int banned_size, set<string> res) {
	if (index == banned_size) {
		s.insert(res); // set을 set에 넣어 중복되는 경우가 없도록 한다.
	}

	for (int i = 0; i < cand[index].size(); i++) {
		if (m[cand[index][i]]) continue; // 이미 선택된 user_id인 경우 건너뜀
		res.insert(cand[index][i]);
		m[cand[index][i]] = true;
		go(index + 1, banned_size, res);
		m[cand[index][i]] = false;
		res.erase(cand[index][i]);
	}

}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	// 불량 사용자 아이디에 가능한 유저 후보를 cand벡터의 해당하는 인덱스에 담는다.
	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			if (banned_id[i].size() != user_id[j].size()) continue;
			bool check = true;
			for (int k = 0; k < banned_id[i].size(); k++) {
				if (banned_id[i][k] == '*') continue;
				if (banned_id[i][k] != user_id[j][k]) {
					check = false;
					break;
				}
			}
			if (check) {
				cand[i].push_back(user_id[j]); // 가능한 후보인 경우
			}
		}
	}

	for (int i = 0; i < user_id.size(); i++) {
		m[user_id[i]] = false;
	}
	set<string> res;
	go(0, banned_id.size(), res);

	answer = s.size();

	return answer;
}

```
