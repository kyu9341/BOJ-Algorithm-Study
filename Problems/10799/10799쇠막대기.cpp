#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	string input; // 입력 문자열 
	stack<char> s;

	getline(cin, input);
	int size = input.size();
	int raser[100000] = {}; // 막대기에 발사된 레이저의 수
	int res = 0;

	for (int i = 0; i < size; i++)
	{
		if (input[i] == '(' && input[i + 1] == ')') // 레이저인 경우
		{
			for (int j = 1; j <= s.size(); j++)
			{
				raser[j]++; // 스택의 사이즈(겹쳐진 막대기 수) 모두 1씩 증가
			}
			i++; // 문자 두 개를 확인했으니 한칸 넘어감
		}
		else // 막대기의 시작 or 끝인 경우
		{
			if (input[i] == '(')
			{
				s.push(input[i]);
			}
			else if (input[i] == ')') // 괄호가 닫힐 때 정산
			{
				res += raser[s.size()] + 1; // 하나의 막대기에는 n + 1개의 조각이 생성
				raser[s.size()] = 0; // 초기화
				s.pop();
			}
		}

	}
	
	cout << res << '\n';


	return 0;
}