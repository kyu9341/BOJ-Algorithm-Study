#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int i = 2; // 2부터 나눠본다
	while(true)
	{
		if (n % i == 0) // 나누어 떨어지면 i 출력
		{
			cout << i << '\n';
			n /= i;
		}
		else
			i++; // 떨어지지 않으면 1씩 증가
		
		if (i > n || n == 0) 
			break;

	}
}