#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool check(string str) {
	
	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			if (s.empty()) return false;
			else if(!s.empty()){
				s.pop();
			}
		}
		else {
			s.push(str[i]);
		}
	}
	// 올바른 괄호 문자열
	return true;
}

string go(string w) {
	
	if (w == "") return "";

	string u, v;
	int left = 0;
	int right = 0;
	for (int i = 0; i < w.size(); i++) {
		if (w[i] == '(') left++;
		else right++;
		if (left == right) {
			u = w.substr(0, i + 1);
			v = w.substr(i + 1);
			break;
		}
	}
	
	if (check(u)) return u + go(v);
	else {
		string str = "(" + go(v) + ")";
		string tmp = u.substr(1, u.size() - 2);
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == '(') str += ")";
			else str += "(";
		}
		return str;
	}
}

string solution(string p) {
	string answer = "";
	
	answer = go(p);

	return answer;
}