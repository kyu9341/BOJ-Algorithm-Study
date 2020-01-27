#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int n; // 입력 10진수 수
	int b; // b진법
	cin >> n >> b;
	string result = ""; // 출력 문자열
	
	while (n > 0)
	{
		int r = n % b; // remainder
		if (r < 10)
			result += (char)(r + '0'); // 형변환
		else
			result += (char)(r - 10 + 'A'); // 10 이상의 수인 경우 아스키 코드로 변환(A~Z)
		n /= b; // 몫이 0보다 크다면 계속 나눔
	}

	reverse(result.begin(), result.end()); // 결과 문자열을 뒤집어 출력
	cout << result << '\n';
}