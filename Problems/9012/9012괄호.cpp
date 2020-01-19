#include<iostream>
#include<string>
#include<stack>

using namespace std;
string distinction(string str);

int main()
{
	int n; // 테스트 케이스 수
	string str; // 판별할 문자열

	cin >> n;
	cin.ignore();

	while (n--)
	{
		getline(cin, str);
		cout << distinction(str) << '\n';
	}
	
	return 0;
}

string distinction(string str) // 문자열이 VPS인지 판별하는 함수
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') // '(' 일 경우 push
		{
			s.push(str[i]);
		}
		else
		{
			if (s.empty()) // 빈 스택에 ')' 가 입력될 경우 NO 리턴
			{
				return "NO";
			}
			s.pop(); // 빈 스택이 아니면 pop
		}
	}
	if (s.empty()) // 반복문이 끝나고 빈 스택이라면 VPS가 맞다
		return "YES"; 
	else
		return "NO";
}