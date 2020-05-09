#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cmath>

using namespace std;
vector<string> cand[8];
map<string, bool> m;
set<set<string>> s;

// 가능한 후보들 중에서 중복되지 않는 경우를 구한다.
void go(int index, int banned_size, set<string> res) {
	if (index == banned_size) {
		s.insert(res); // set을 set에 넣어 중복되는 경우가 없도록 한다.
	}

	for (int i = 0; i < cand[index].size(); i++) {
		if (m[cand[index][i]]) continue; // 이미 선택된 user_id인 경우 건너뜀
		res.insert(cand[index][i]);
		m[cand[index][i]] = true;
		go(index + 1, banned_size, res);
		m[cand[index][i]] = false;
		res.erase(cand[index][i]);
	}

}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	// 불량 사용자 아이디에 가능한 유저 후보를 cand벡터의 해당하는 인덱스에 담는다.
	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			if (banned_id[i].size() != user_id[j].size()) continue;
			bool check = true;
			for (int k = 0; k < banned_id[i].size(); k++) {
				if (banned_id[i][k] == '*') continue;
				if (banned_id[i][k] != user_id[j][k]) {
					check = false;
					break;
				}
			}
			if (check) {
				cand[i].push_back(user_id[j]);
			}
		}
	}

	for (int i = 0; i < user_id.size(); i++) {
		m[user_id[i]] = false;
	}
	set<string> res;
	go(0, banned_id.size(), res);
	
	answer = s.size();

	return answer;
}
