#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	int a, b; // a진법, b진법
	cin >> a >> b;
	int n; // a진법 자리수
	cin >> n;
	int result = 0; // a진수 -> 10진수
	while (n--) // a진법 -> 10진법 변환
	{
		int num; // 각 자리수별 수
		cin >> num;
		
		result = result * a + num;  // 자리수만큼 a를 곱하고 마지막 자리 num을 더함
	}
	stack<int> s;
	while (result > 0) // 10진수 -> b진수 변환
	{
		int r = result % b;
		s.push(r);
		result /= b;
	}
	// 높은 자리부터 나오기 때문에 스택에 쌓아 뒤집어 출력
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
}