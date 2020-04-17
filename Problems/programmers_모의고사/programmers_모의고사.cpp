#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;
int answer1[] = { 1, 2, 3, 4, 5 }; // 1�� �������� ����
int answer2[] = { 2, 1, 2, 3, 2, 4, 2, 5 }; // 2�� �������� ����
int answer3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; // 3�� �������� ����

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

	// �������� ����(������ ����), ���� ��� ��ȣ ��������
	sort(tmp.begin(), tmp.end(), compare);
	
	// ������ ���� ��� ������� �߰�
	if (tmp[0].first == tmp[1].first) {
		answer.push_back(tmp[0].second);
		answer.push_back(tmp[1].second);
		if (tmp[1].first == tmp[2].first)
			answer.push_back(tmp[2].second);
	}
	else { // ������ �ٸ� ��� ���� ���� ����� �߰�
		answer.push_back(tmp[0].second);
	}


	return answer;
}