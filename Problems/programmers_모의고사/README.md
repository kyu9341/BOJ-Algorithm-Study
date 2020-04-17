# 프로그래머스 - 모의고사

## 모의고사

### 문제
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

### 제한 조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

### 입출력 예
answers	return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]

#### 입출력 예 설명
- 입출력 예 #1
	- 수포자 1은 모든 문제를 맞혔습니다.
	- 수포자 2는 모든 문제를 틀렸습니다.
	- 수포자 3은 모든 문제를 틀렸습니다.
	- 따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

- 입출력 예 #2
	- 모든 사람이 2문제씩을 맞췄습니다.
	
### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/42840>

### solve
- 각 수포자의 패턴을 배열로 저장하여 정답을 몇 개 맞췄는지를 카운트한다.
	- 각 수포자의 정담 수는 정답 벡터를 모두 확인하는데, 이때 수포자의 패턴이 담긴 배열의 인덱스에 나머지 연산자(%)를 이용하여 반복적으로 접근한다.
- 각 수포자의 점수와 번호를 pair형 벡터에 담고 점수를 기준으로 내림차순, 점수가 같다면 번호를 오름차순으로 하도록 정렬한다.
- 이후 점수가 가장 높은 수포자와 다음 수포자의 점수가 같다면 순서대로 반환할 벡터에 추가하고 아니라면 정답을 가장 많이 맞춘 사람만 추가한다.


### 코드 설명
```C++
#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;
int answer1[] = { 1, 2, 3, 4, 5 }; // 1번 수포자의 패턴
int answer2[] = { 2, 1, 2, 3, 2, 4, 2, 5 }; // 2번 수포자의 패턴
int answer3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; // 3번 수포자의 패턴

int count1(vector<int>& answers) {
	int count = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == answer1[i % 5]) count++;
	}
	return count;
}

int count2(vector<int>& answers) {
	int count = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == answer2[i % 8]) count++;
	}
	return count;
}

int count3(vector<int>& answers) {
	int count = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == answer3[i % 10]) count++;
	}
	return count;
}
bool compare(pair<int, int> u, pair<int, int> v) {
	if (u.first == v.first) return u.second < v.second;
	return u > v;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<pair<int, int>> tmp;

	tmp.push_back(make_pair(count1(answers), 1));
	tmp.push_back(make_pair(count2(answers), 2));
	tmp.push_back(make_pair(count3(answers), 3));

	// 내림차순 정렬(점수를 기준), 같은 경우 번호 오름차순
	sort(tmp.begin(), tmp.end(), compare);

	// 점수가 같은 경우 순서대로 추가
	if (tmp[0].first == tmp[1].first) {
		answer.push_back(tmp[0].second);
		answer.push_back(tmp[1].second);
		if (tmp[1].first == tmp[2].first)
			answer.push_back(tmp[2].second);
	}
	else { // 점수가 다른 경우 가장 높은 사람만 추가
		answer.push_back(tmp[0].second);
	}


	return answer;
}
```
