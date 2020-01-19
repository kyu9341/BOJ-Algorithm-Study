#include<iostream>
#include<string>
#include<stack>

using namespace std;

void sprint(stack<char>& s) // 스택이 비워질 때까지 출력하는 함수
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	string str; // 입력 문자열
	stack<char> s;

	getline(cin, str);
	bool tag = false; // 태그 내부인지 검사

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<') // '<'를 만나고 스택이 비어있지 않다면 스택을 모두 출력
		{
			sprint(s);
			cout << str[i];
			tag = true; // 태그 내부 판단
		}
		else if (str[i] == '>')
		{
			cout << str[i];
			tag = false;
		}
		else if(tag)
		{
			cout << str[i]; // 태그 내부인 경우 그대로 출력
		}
		else
		{
			if (str[i] == ' ') // 공백을 만난 경우 스택을 비움
			{
				sprint(s);
				cout << str[i]; // 공백 출력
			}
			else
				s.push(str[i]); // 아니라면 스택에 push
		}

	}
	sprint(s); // 스택이 남아있다면 모두 출력
	cout << '\n';

	return 0;
}