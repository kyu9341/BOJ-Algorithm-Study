#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	// �������� ����
	sort(people.begin(), people.end(), greater<int>());
	int right = people.size() - 1; // ���� ������ ����� ��ġ
	for (int i = 0; i < people.size(); i++) {
		if (i == right) { // �������� ��� ������ ��Ʈ�� �߰��ϰ� ����
			answer++;
			break;
		}
		else if (i > right) break; // ��� �ο��� �¿� ���
		int sum = people[i]; // ������ ���� �ʱ�ȭ
		while (sum + people[right] <= limit) {
			sum += people[right--]; // ���� ��� �� ���� ������ ����� �¿��.
		}
		answer++;
	}
	return answer;
}
