#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	stack<char> s;
	string result; // ��� ���ڿ�

	for (int i = 0; i < str.length(); i++) {

		if (str[i] >= 'A' && str[i] <= 'Z') {
			result += str[i];
		}
		else {
			switch (str[i]) {
			case '(':
				s.push(str[i]);
				break;
				// ��Ģ�����ڸ� ���� ��� ���ÿ� ���� �����ں��� �켱������ ���ų� ���� ��ȣ�� result�� �߰�
			case '+':
			case '-':
				// +, - �����ڸ� ���� ���, ���ÿ� ���� �ִ� ( �� �����ϰ� ���� �켱������ ���ų� ������ result�� �߰�
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				// ������ ����ų� ( �̹Ƿ� �����ڸ� ���ÿ� push
				s.push(str[i]);
				break;
			case '*':
			case '/':
				// *, / �����ڸ� ���� ���, ���ÿ� ���� �ִµ� �װ� *, /�̸� �켱 ������ �����Ƿ� result�� �߰�
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}
				// ������ ����ų� �켱������ �� ���� +, - �̹Ƿ� �����ڸ� ���ÿ� push
				s.push(str[i]);
				break;
			case ')':
				// ) �� ������ ( ���� result�� �߰�
				while (s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.pop(); // ��ȣ ���� ������ �� result�� �߰������� ( �� pop�ؼ� �����ش�.
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
