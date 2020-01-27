#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{
	int b; // b진법
	string n; // 수 n

	cin >> n;
	cin >> b;

	int result = 0;

	for (int i = n.size() - 1, j = 1; i >= 0; i--, j*=b) // b진법 수 n의 뒤에서부터 확인, j에 자리수에 따른 제곱적용
	{
		if((int)(n[i] -'0') < 10)
			result += (int)(n[i] - '0') * j; // 형변환 후 연산
		else
		{
			result += ((int)(n[i] - 'A') + 10) * j; // 10보다 큰 경우 처리
		}
	}
	cout << result << '\n';
}