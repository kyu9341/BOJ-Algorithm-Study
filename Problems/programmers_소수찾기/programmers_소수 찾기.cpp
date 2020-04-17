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
	// ���� ���ڿ��� �� ���ڿ��� �ƴϰ� �ߺ����� ���� ���
	if (cur != "" && !visit[stoi(cur)]) {
		int num = stoi(cur);
		if (!visit[num]) {
			visit[num] = true; // �湮 ó��
			if (!prime[num])cnt++; // �Ҽ��� ��� ī��Ʈ
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (check[i]) continue; // �̹� ����� ���̸� ���
		check[i] = true;
		go(index + 1, numbers, cur + numbers[i]);
		check[i] = false;


	}

}



int solution(string numbers) {
	int answer = 0;
	prime[0] = true;
	prime[1] = true;
	// �����佺�׳׽��� ü
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
