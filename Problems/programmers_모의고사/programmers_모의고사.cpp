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