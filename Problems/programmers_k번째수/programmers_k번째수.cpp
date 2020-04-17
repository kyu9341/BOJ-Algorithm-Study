#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> tmp; // 이번 구간의 원소들을 담을 벡터
	for (int i = 0; i < commands.size(); i++) {
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
			tmp.push_back(array[j]);
		}
		sort(tmp.begin(), tmp.end()); // 현재 구간 정렬
		answer.push_back(tmp[commands[i][2] - 1]); // 정렬된 구간에서의 k번째 수 삽입
		tmp.clear(); // 초기화
	}

	return answer;
}