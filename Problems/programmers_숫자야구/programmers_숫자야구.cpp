#include <string>
#include <vector>
#include <set>
#include <string>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	// 1~9의 숫자이므로 가능한 모든 범위는 123 ~ 987
	for (int i = 123; i <= 987; i++) {
		string cur = to_string(i);
		// 모두 서로 다른 숫자이므로 같은 숫자가 있는 경우는 확인 안함
		if (cur[0] == cur[1] || cur[1] == cur[2] || cur[0] == cur[2]) continue; 
		// 0이 있는 경우는 불가능
		if (cur[0] == '0' || cur[1] == '0' || cur[2] == '0') continue;

		// 조건을 만족하는지 확인할 변수
		bool check = true;

		for (int j = 0; j < baseball.size(); j++) {
			string num = to_string(baseball[j][0]);
			int s = 0; // 스트라이크
			int b = 0; // 볼

			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					// 스트라이크인 경우
					if (k == l && num[k] == cur[l]) s++;
					// 볼인 경우
					else if (num[k] == cur[l]) b++;
				}
			}
			// 현재 조건을 만족하는지 확인
			if (s != baseball[j][1] || b != baseball[j][2]) {
				check = false;
				break;
			}

		}
		
		if (check) answer++;
	}

	return answer;
}