#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 테스트 케이스 수
	string str; // 입력 문자열

	cin >> n;
	cin.ignore();
	//cin.get();
	// 둘 중 하나를 해줘야함. cin >> n 이후 getline() 입력을 받을 때 
	// 버퍼에 남아있는 개행문자를 처리해주어야 다음건 부터 정상적으로 입력을 받음

	stack<char> s;


	while (n--)
	{
		getline(cin, str); 
		str += '\n'; // std::string -> getline() 함수의 경우 따로 제한자를 걸어두지 않는다면 엔터('\n')인데
		// \n 직전까지를 하나의 입력으로 받아들이고 \n을 버린다. 이 문제에서는 \n까지 입력으로 받아들여야
		// 아래의 조건에서 정상적으로 처리가 가능하므로 추가해주도록 함.

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ' && str[i] != '\n') // 띄어쓰기나 개행문자가 아닌 경우 push
			{
				s.push(str[i]);
			}
			else
			{
				while (!s.empty()) // 띄어쓰기 또는 개행문자를 만난 경우 현재까지 스택에 입력된 값을 모두 출력 후 pop
				{
					cout << s.top();
					s.pop();
				}
				cout << str[i]; // 입력된 띄어쓰기 or 개행문자를 출력
			}

		}
	}

	return 0;
}

