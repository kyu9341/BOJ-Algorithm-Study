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

void init(string s) { // 문자열로 된 집합을 벡터로 변환
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
	init(s); // 문자열을 벡터로 변환
	// 벡터의 크기 순으로 오름차순 정렬
	sort(a.begin(), a.end(), [](vector<int> u, vector<int> v) {
		return u.size() < v.size();
		});
	// 크기가 1인 벡터부터 중복이 아닌 수가 나오는 경우 answer에 추가
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