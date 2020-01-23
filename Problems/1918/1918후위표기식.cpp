#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	stack<char> s;
	string result; // 결과 문자열

	for (int i = 0; i < str.length(); i++) {

		if (str[i] >= 'A' && str[i] <= 'Z') {
			result += str[i];
		}
		else {
			switch (str[i]) {
			case '(':
				s.push(str[i]);
				break;
				// 사칙연산자를 만난 경우 스택에 현재 연산자보다 우선순위가 높거나 같은 기호는 result에 추가
			case '+':
			case '-':
				// +, - 연산자를 만난 경우, 스택에 뭐가 있던 ( 를 제외하고 전부 우선순위가 높거나 같으니 result에 추가
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				// 스택이 비었거나 ( 이므로 연산자를 스택에 push
				s.push(str[i]);
				break;
			case '*':
			case '/':
				// *, / 연산자를 만난 경우, 스택에 뭐가 있는데 그게 *, /이면 우선 순위가 같으므로 result에 추가
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}
				// 스택이 비었거나 우선순위가 더 낮은 +, - 이므로 연산자를 스택에 push
				s.push(str[i]);
				break;
			case ')':
				// ) 를 만나면 ( 까지 result에 추가
				while (s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.pop(); // 괄호 안의 내용을 다 result에 추가했으면 ( 도 pop해서 날려준다.
				break;
			}
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result << "\n";
}
