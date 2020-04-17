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
	return sum <= M; // 현재 값으로 예산을 맞출 수 있는지 확인
}

int solution(vector<int> budgets, int M) {
	int answer = 0;

	int right = 0;
	// 지원한 예산중 최댓값을 right로 지정
	for (int i = 0; i < budgets.size(); i++) {
		if (right < budgets[i]) right = budgets[i];
	}

	int left = 1;

	// 이분 탐색
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