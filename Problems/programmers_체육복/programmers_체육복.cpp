#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	// ��ü �л��� ���¸� ��� ����
	// ������ ���� �Ҿ�������� ���� �л��� 0
	vector<int> v(n + 1, 0);
	
	// ü������ �Ҿ���� �л��� -1
	for (int i = 0; i < lost.size(); i++)
		v[lost[i]] = -1;

	// ���� ü������ �ִ� �л��� 1, ��, ���� ü������ �����Դµ� �Ҿ���ȴٸ� 0
	for (int i = 0; i < reserve.size(); i++) {
		if (v[reserve[i]] == -1) {
			v[reserve[i]] = 0;
		}
		else {
			v[reserve[i]] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] == 1) { // ������ �ִ� �л��� ���
			if (i >= 2 && v[i - 1] == -1) { // �� �л��� ���ٸ� �����ش�.
				v[i] = 0;
				v[i - 1] = 0;
			}
			else if (i + 1 <= 30 && v[i + 1] == -1) { // �� �л��� �ְ� �� �л��� ���ٸ� �����ش�.
				v[i] = 0;
				v[i + 1] = 0;
			}
		}
	}
	answer = n;
	for (int i = 1; i <= n; i++) {
		if (v[i] == -1) answer--; // ������ �� ���� �л��� ���� ��ü �л��� ������ ����.
	}

	return answer;
}