#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<climits>
#include<cmath>

using namespace std;
const int MAX = 100000;
vector<vector<int>> a;
bool check[MAX + 1];

void init(string s) { // ���ڿ��� �� ������ ���ͷ� ��ȯ
	int cnt = 0;
	string num = "";
	vector<int> tmp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '{') {
			cnt++;
			continue;
		}
		else if (s[i] == '}') {
			if (cnt == 2) {
				tmp.push_back(stoi(num));
				num = "";
				a.push_back(tmp);
				tmp.clear();
			}
			cnt--;
			continue;
		}
		if (cnt == 2) {
			if (s[i] == ',') {
				tmp.push_back(stoi(num));
				num = "";
			}
			else {
				num += s[i];
			}
		}
	}
}

vector<int> solution(string s) {
	vector<int> answer;
	init(s); // ���ڿ��� ���ͷ� ��ȯ
	// ������ ũ�� ������ �������� ����
	sort(a.begin(), a.end(), [](vector<int> u, vector<int> v) {
		return u.size() < v.size();
		});
	// ũ�Ⱑ 1�� ���ͺ��� �ߺ��� �ƴ� ���� ������ ��� answer�� �߰�
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (!check[a[i][j]]) {
				answer.push_back(a[i][j]);
				check[a[i][j]] = true;
				break;
			}
		}
	}

	return answer;
}