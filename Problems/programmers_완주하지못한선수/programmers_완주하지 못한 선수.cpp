#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	// ��Ƽ�¿� ����
	multiset<string> ps;
	multiset<string> cs;

	for (int i = 0; i < participant.size(); i++)
		ps.insert(participant[i]);
	for (int i = 0; i < completion.size(); i++)
		cs.insert(completion[i]);

	// �������� ���Ѵ�.
	vector<string> ans(1);
	set_difference(ps.begin(), ps.end(), cs.begin(), cs.end(), ans.begin());

	answer = ans[0];


	return answer;
}