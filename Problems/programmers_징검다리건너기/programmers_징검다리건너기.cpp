#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> stones, int k, int mid) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		// ���� �ο� ���� ���� ���ں��� �� ū ��찡 k�� �̻� ���ӵȴٸ� �Ұ���
		if (stones[i] < mid) {
			cnt++;
			if (cnt >= k) return false;
		}
		else cnt = 0;
	}
	// ���� ���ڰ� 0�̵Ǵ� ��찡 k�� �̻� ���ӵ��� �ʴ´ٸ� ����
	return true;
}


int solution(vector<int> stones, int k) {
	int answer = 0;

	int right = *max_element(stones.begin(), stones.end());
	int left = 1;

	// ¡�˴ٸ��� �ǳʴ� �ο� ���� �������� �̺�Ž��
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