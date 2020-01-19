#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string init; // 초기 문자열
	int n; // 입력할 명령어 개수
	stack<char> s1, s2; // 왼쪽 스택, 오른쪽 스택
	// 커서를 두 스택의 중간으로 취급
	getline(cin, init);
	cin >> n;
	cin.ignore();

	for (auto x : init)
	{
		s1.push(x); // 초기 문자열을 왼쪽 스택에 모두 push
	}

	while (n--)
	{
		string cmd;
		getline(cin, cmd);
		if (cmd == "L" && !s1.empty()) // 커서를 왼쪽으로 한 칸 옮기는 명령
		{
			s2.push(s1.top()); // 왼쪽 스택의 top원소를 오른쪽 스택으로 옮김
			s1.pop();
		}
		if(cmd == "D" && !s2.empty()) // 커서를 오른쪽을 한 칸 옮기는 명령
		{
			s1.push(s2.top()); // 오른쪽 스택의 top원소를 왼쪽 스택으로 옮김
			s2.pop();
		}
		if (cmd == "B" && !s1.empty()) // 커서 왼쪽의 원소를 삭제
		{
			s1.pop();
		}
		if (cmd[0] == 'P') // 커서의 왼쪽에 문자 삽입
		{
			s1.push(cmd[2]);
		}
	}

	while (!s1.empty()) // 스택은 최상위 원소부터 출력이 가능하므로
	{					// 우측 스택으로 좌측 스택의 원소를 모두 옮김
		s2.push(s1.top());
		s1.pop();
	}

	while (!s2.empty()) // 이후 우측 스택의 원소를 차례로 출력
	{
		cout << s2.top();
		s2.pop();
	}
	cout << '\n';

	return 0;
}
