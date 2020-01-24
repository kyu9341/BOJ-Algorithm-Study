#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string a, b, c, d;
	// 문자열로 입력받아 문자열 연산 후 정수 변환하여 정수 연산 후 출력
	cin >> a >> b >> c >> d;
	string ab; 
	ab = a + b;
	string cd;
	cd = c + d;

	long long result = stoll(ab) + stoll(cd); // 문자열을 long long 형으로 바꾸는 함수
	// 각 수의 범위가 (1 ≤ A, B, C, D ≤ 1,000,000) 이므로
	cout << result << '\n';
}