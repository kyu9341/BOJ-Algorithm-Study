#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 10000;
bool visit[MAX + 1];

bool dfs(string node, vector<vector<string>>& tickets, vector<string>& answer, int index) {
	answer.push_back(node);
	if (index == tickets.size()) { // 모든 티켓을 사용한 경우
		return true;
	}
	
	for (int i = 0; i < tickets.size(); i++) {
		string next = tickets[i][1];
		string now = tickets[i][0];
		// 다음 출발지가 현재 위치와 일치하는 아직 사용하지 않은 티켓이 있는지 확인
		if (now == node && visit[i] == false) {
			visit[i] = true;
			if (dfs(next, tickets, answer, index + 1)) return true;
			visit[i] = false;
		}
	}
	answer.pop_back();

	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end());
	dfs("ICN", tickets, answer, 0);

	return answer;
}