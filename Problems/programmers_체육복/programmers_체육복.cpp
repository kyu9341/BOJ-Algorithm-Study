#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	// 전체 학생의 상태를 담는 벡터
	// 여벌이 없고 잃어버리지도 않은 학생은 0
	vector<int> v(n + 1, 0);
	
	// 체육복을 잃어버린 학생은 -1
	for (int i = 0; i < lost.size(); i++)
		v[lost[i]] = -1;

	// 여벌 체육복이 있는 학생은 1, 단, 여벌 체육복을 가져왔는데 잃어버렸다면 0
	for (int i = 0; i < reserve.size(); i++) {
		if (v[reserve[i]] == -1) {
			v[reserve[i]] = 0;
		}
		else {
			v[reserve[i]] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] == 1) { // 여벌이 있는 학생인 경우
			if (i >= 2 && v[i - 1] == -1) { // 앞 학생이 없다면 빌려준다.
				v[i] = 0;
				v[i - 1] = 0;
			}
			else if (i + 1 <= 30 && v[i + 1] == -1) { // 앞 학생이 있고 뒷 학생이 없다면 빌려준다.
				v[i] = 0;
				v[i + 1] = 0;
			}
		}
	}
	answer = n;
	for (int i = 1; i <= n; i++) {
		if (v[i] == -1) answer--; // 빌려준 뒤 없는 학생의 수만 전체 학생의 수에서 뺀다.
	}

	return answer;
}