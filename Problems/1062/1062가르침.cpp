#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<set>

using namespace std;
int n, k;
set<char> s;
vector<set<char>> v;
int ans = 0;

void dfs(int index, char start) {
	// k - 5 ���� �̾Ƽ� �ش� ���ڷ� �� ���� ���� �� �ִ��� Ȯ��
	if (index == k - 5) {
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			bool ok = true;
			for (auto it = v[i].begin(); it != v[i].end(); it++) {
				if (s.find(*it) == s.end()) {
					ok = false;
					break;
				}
			}
			// ���Ե��� ���� �ٸ� ���ڰ� ���� ���
			if (ok || v[i].empty()) cnt++;
		}
		if (ans < cnt) ans = cnt;
		return;
	}

	for (char i = start; i <= 'z'; i++) {
		if (s.find(i) != s.end()) continue;
		s.insert(i);
		dfs(index + 1, i);
		s.erase(i);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// 5���� ���ڸ� ���� �Է�
	s.insert('a');
	s.insert('n');
	s.insert('t');
	s.insert('i');
	s.insert('c');

	cin >> n >> k;
	cin.ignore();
	v.resize(n);
	// ���� �ܾ��� �⺻ 5���� ���ڸ� ���� ���ڸ� ������ set�� �߰�
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 4; j < input.size() - 4; j++) {
			if (s.find(input[j]) == s.end()) {
				v[i].insert(input[j]);
			}
		}
	}
	// 5�� �̸��� ���� ����ġ�� ���� �� �ִ� �ܾ ����
	if(k >= 5) dfs(0, 'a');

	cout << ans << '\n';
}