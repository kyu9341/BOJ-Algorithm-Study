#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> stones, int k, int mid) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		// 현재 인원 수가 돌의 숫자보다 더 큰 경우가 k번 이상 연속된다면 불가능
		if (stones[i] < mid) {
			cnt++;
			if (cnt >= k) return false;
		}
		else cnt = 0;
	}
	// 돌의 숫자가 0이되는 경우가 k번 이상 연속되지 않는다면 가능
	return true;
}


int solution(vector<int> stones, int k) {
	int answer = 0;

	int right = *max_element(stones.begin(), stones.end());
	int left = 1;

	// 징검다리를 건너는 인원 수를 기준으로 이분탐색
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(stones, k, mid)) {
			left = mid + 1;
			if (answer < mid) {
				answer = mid;
			}
		}
		else {
			right = mid - 1;
		}
	}

	return answer;
}