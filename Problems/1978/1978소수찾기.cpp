#include<iostream>

using namespace std;

int main(void)
{
	int n; // test case 수
	cin >> n;
	int count = 0; // 소수의 개수
	while (n--)
	{
		int num;
		bool check = true;
		cin >> num;
		if (num == 1) check = false; // 1은 소수가 아님
		for (int i = 2; i*i <= num; i++) // 루트 n 까지만 확인하여 나눠떨어지지 않으면 소수
		{
			if (num % i == 0)
				check = false;
		}
		if (check)
			count++;
	}
	cout << count << '\n';

}