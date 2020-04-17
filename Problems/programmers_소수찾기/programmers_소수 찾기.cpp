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
