#include <string>
#include <vector>
#include <set>
#include <string>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	// 1~9�� �����̹Ƿ� ������ ��� ������ 123 ~ 987
	for (int i = 123; i <= 987; i++) {
		string cur = to_string(i);
		// ��� ���� �ٸ� �����̹Ƿ� ���� ���ڰ� �ִ� ���� Ȯ�� ����
		if (cur[0] == cur[1] || cur[1] == cur[2] || cur[0] == cur[2]) continue; 
		// 0�� �ִ� ���� �Ұ���
		if (cur[0] == '0' || cur[1] == '0' || cur[2] == '0') continue;

		// ������ �����ϴ��� Ȯ���� ����
		bool check = true;

		for (int j = 0; j < baseball.size(); j++) {
			string num = to_string(baseball[j][0]);
			int s = 0; // ��Ʈ����ũ
			int b = 0; // ��

			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					// ��Ʈ����ũ�� ���
					if (k == l && num[k] == cur[l]) s++;
					// ���� ���
					else if (num[k] == cur[l]) b++;
				}
			}
			// ���� ������ �����ϴ��� Ȯ��
			if (s != baseball[j][1] || b != baseball[j][2]) {
				check = false;
				break;
			}

		}
		
		if (check) answer++;
	}

	return answer;
}