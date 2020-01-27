#include<iostream>

using namespace std;
const int MAX = 1000000;

int prime[MAX]; // 소수들을 담을 배열
bool check[MAX + 1]; // check의 인덱스가 소수면 참
int pn = 0; // 소수의 개수

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= MAX; i++) // 에라토스테네스의 체
	{
		if (check[i] == false)  // 지워지지 않았다면(소수라면)
		{
			prime[pn++] = i; // 소수 배열에 추가
			for (int j = i + i; j <= MAX; j += i) // i*i 부터 시작을 하면 정수의 범위를 넘어 런타임 에러가 남
			{
				check[j] = true;
			}
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			return 0;

		for (int i = 1; i < pn ; i++) // 3부터 시작
		{
			if (!check[n - prime[i]]) // n - prime[i] 가 소수면 성립
			{
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}
	return 0;
}