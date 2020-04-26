#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	// 내림차순 정렬
	sort(people.begin(), people.end(), greater<int>());
	int right = people.size() - 1; // 가장 가벼운 사람의 위치
	for (int i = 0; i < people.size(); i++) {
		if (i == right) { // 같아지는 경우 마지막 보트를 추가하고 종료
			answer++;
			break;
		}
		else if (i > right) break; // 모든 인원을 태운 경우
		int sum = people[i]; // 누적될 무게 초기화
		while (sum + people[right] <= limit) {
			sum += people[right--]; // 남은 사람 중 가장 가벼운 사람을 태운다.
		}
		answer++;
	}
	return answer;
}
