#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void)
{
	stack<int> s;
	int n; // 테스트 케이스 수
	string ans; // 출력할 문자열

	cin >> n; 

	int m = 0; // 스택의 최댓값

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x > m) // x 가 스택에 들어왔던 최댓값보다 큰 경우
		{
			while (x > m)
			{
				s.push(++m); // 스택에 push
				ans += '+';
			}
			s.pop();
			ans += '-';
		}
		else
		{
			bool found = false;  // x 가 더 작은 경우 현재 스택의 맨 위의 값과 같은지 판별
			if (!s.empty())
			{
				if (s.top == x) // 같으면 스택 수열을 이룰 수 있음
					found = true;
				s.pop();
				ans += '-';
			}

			if (!found)
			{
				cout << "NO" << '\n';
				return 0;
			}
				
		}
		
	}

	for (auto x : ans)
		cout << x << '\n';

	return 0;
}