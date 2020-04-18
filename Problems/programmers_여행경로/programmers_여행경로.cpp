#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 10000;
bool visit[MAX + 1];

bool dfs(string node, vector<vector<string>>& tickets, vector<string>& answer, int index) {
	answer.push_back(node);
	if (index == tickets.size()) { // ��� Ƽ���� ����� ���
		return true;
	}
	
	for (int i = 0; i < tickets.size(); i++) {
		string next = tickets[i][1];
		string now = tickets[i][0];
		// ���� ������� ���� ��ġ�� ��ġ�ϴ� ���� ������� ���� Ƽ���� �ִ��� Ȯ��
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