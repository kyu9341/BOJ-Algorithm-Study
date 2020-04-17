#include <string>
#include <vector>

using namespace std;

bool check(vector<int> budgets, int M, int mid) {
	long long sum = 0;
	for (int i = 0; i < budgets.size(); i++) {
		if (mid > budgets[i]) {
			sum += budgets[i];
		}
		else {
			sum += mid;
		}
	}
	return sum <= M; // ���� ������ ������ ���� �� �ִ��� Ȯ��
}

int solution(vector<int> budgets, int M) {
	int answer = 0;

	int right = 0;
	// ������ ������ �ִ��� right�� ����
	for (int i = 0; i < budgets.size(); i++) {
		if (right < budgets[i]) right = budgets[i];
	}

	int left = 1;

	// �̺� Ž��
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (check(budgets, M, mid)) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return answer;
}