#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	vector<pair<int, int>> v;
	// ���� ī���� ������ ����, ���� ���� v�� ����
	for (int i = 1; i * i <= red; i++) {
		if (red % i == 0) v.push_back(make_pair(red / i, i));
	}

	for (int i = 0; i < v.size(); i++) {
		// ���������� ������ cur�� ����
		int cur = (v[i].first + 2) * (v[i].second + 2) - red;
		// ��ġ�ϴ� ��� ��� ����
		if (brown == cur) {
			answer.push_back(v[i].first + 2);
			answer.push_back(v[i].second + 2);
			break;
		}
	}


	return answer;
}