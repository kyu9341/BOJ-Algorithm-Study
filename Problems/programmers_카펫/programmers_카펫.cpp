#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	vector<pair<int, int>> v;
	// 빨간 카펫의 가능한 가로, 세로 상을 v에 저장
	for (int i = 1; i * i <= red; i++) {
		if (red % i == 0) v.push_back(make_pair(red / i, i));
	}

	for (int i = 0; i < v.size(); i++) {
		// 갈색격자의 개수를 cur에 저장
		int cur = (v[i].first + 2) * (v[i].second + 2) - red;
		// 일치하는 경우 결과 저장
		if (brown == cur) {
			answer.push_back(v[i].first + 2);
			answer.push_back(v[i].second + 2);
			break;
		}
	}


	return answer;
}