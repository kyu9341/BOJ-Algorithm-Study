# 프로그래머스 - 호텔 방 배정

## 호텔 방 배정

### 문제
[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]

스노우타운에서 호텔을 운영하고 있는 스카피는 호텔에 투숙하려는 고객들에게 방을 배정하려 합니다. 호텔에는 방이 총 k개 있으며, 각각의 방은 1번부터 k번까지 번호로 구분하고 있습니다. 처음에는 모든 방이 비어 있으며 스카피는 다음과 같은 규칙에 따라 고객에게 방을 배정하려고 합니다.

1. 한 번에 한 명씩 신청한 순서대로 방을 배정합니다.
2. 고객은 투숙하기 원하는 방 번호를 제출합니다.
3. 고객이 원하는 방이 비어 있다면 즉시 배정합니다.
4. 고객이 원하는 방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 배정합니다.
예를 들어, 방이 총 10개이고, 고객들이 원하는 방 번호가 순서대로 [1, 3, 4, 1, 3, 1] 일 경우 다음과 같이 방을 배정받게 됩니다.

원하는 방 번호	배정된 방 번호
1	1
3	3
4	4
1	2
3	5
1	6
전체 방 개수 k와 고객들이 원하는 방 번호가 순서대로 들어있는 배열 room_number가 매개변수로 주어질 때, 각 고객에게 배정되는 방 번호를 순서대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

### [제한사항]
- k는 1 이상 1012 이하인 자연수입니다.
- room_number 배열의 크기는 1 이상 200,000 이하입니다.
- room_number 배열 각 원소들의 값은 1 이상 k 이하인 자연수입니다.
- room_number 배열은 모든 고객이 방을 배정받을 수 있는 경우만 입력으로 주어집니다.
- 예를 들어, k = 5, room_number = [5, 5] 와 같은 경우는 방을 배정받지 못하는 고객이 발생하므로 이런 경우는 입력으로 주어지지 않습니다.

### [입출력 예]
k	room_number	result
10	[1,3,4,1,3,1]	[1,3,4,2,5,6]


### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/64063>

### solve
- 유니온 파인드의 부모를 찾는 방식을 응용하여 원하는 방의 부모로 다음 방의 위치를 저장한다.
- getParent함수를 사용하면 현재 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 찾을 수 있다.
- 또한 k의 범위가 10^12이므로 배열을 사용하면 메모리 초과가 날 것이므로 map을 사용하였다.
	- 맵에 없는 키 값에 접근하면 0을 받게 되므로 맵의 원하는 방의 번호를 키값으로 하여 접근하였을 때 0이라면 현재 방이 빈 방이라는 뜻이므로 현재 방을 할당하고 맵에 다음 방의 위치를 저장한다.
	- 만약 원하는 방이 비어있지 않다면 getParent함수로 이어지는 다음 빈 방의 번호를 찾아 그 방을 할당하고, 맵에 그 방의 다음 위치를 저장한다.


### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<map>

using namespace std;
typedef long long ll;
map<ll, ll> m;

ll getParent(ll x) {
	if (m[x] == 0) return x; // 다음 방이 비어있는 경우
	return m[x] = getParent(m[x]); // 다음 빈 방이 나올때 까지 확인
}


vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (int i = 0; i < room_number.size(); i++) {
		ll now = room_number[i];
		if (m[now] == 0) { // 원하는 방번호 배정이 가능한 경우
			answer.push_back(now);
			m[now] = getParent(now + 1);  // 다음 방의 위치 저장
		}
		else { // 불가능한 경우
			ll next = getParent(now); // 다음 이어지는 빈 방의 번호를 찾는다.
			answer.push_back(next);
			m[next] = getParent(next + 1); // 찾은 방의 다음 방의 위치 저장
		}
	}

	return answer;
}

```
