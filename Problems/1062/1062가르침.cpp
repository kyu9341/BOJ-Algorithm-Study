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
	// k - 5 개를 뽑아서 해당 문자로 몇 개를 만들 수 있는지 확인
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
			// 포함되지 않은 다른 문자가 없는 경우
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
	// 5개의 문자를 먼저 입력
	s.insert('a');
	s.insert('n');
	s.insert('t');
	s.insert('i');
	s.insert('c');

	cin >> n >> k;
	cin.ignore();
	v.resize(n);
	// 각각 단어의 기본 5개의 문자를 외의 문자만 각각의 set에 추가
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 4; j < input.size() - 4; j++) {
			if (s.find(input[j]) == s.end()) {
				v[i].insert(input[j]);
			}
		}
	}
	// 5개 미만의 수를 가르치면 읽을 수 있는 단어가 없음
	if(k >= 5) dfs(0, 'a');

	cout << ans << '\n';
}