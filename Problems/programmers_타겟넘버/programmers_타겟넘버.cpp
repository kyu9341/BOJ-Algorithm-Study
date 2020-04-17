#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int target, int index, int sum, int count) {
	if (index == numbers.size()) {
		if (sum == target) {
			return 1; // Ÿ�� �ѹ��� ���� ���
		}
		else {
			return 0; // ������ ���� ���
		}
	}

	count = dfs(numbers, target, index + 1, sum + numbers[index], count) + dfs(numbers, target, index + 1, sum - numbers[index], count);

	return count;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	answer = dfs(numbers, target, 0, 0, 0);

	return answer;
}