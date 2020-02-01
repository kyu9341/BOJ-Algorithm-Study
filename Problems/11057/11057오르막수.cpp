#include<iostream>
using namespace std;
const int mod = 10007;
long long d[1001][10]; // d[i][j] = 이전 수가 j인 i자리 오르막 수의 개수
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++) // 한자리 수는 모두 1로 초기화
		d[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int l = j; l <= 9; l++) // j 보다 크거나 같은 수가 들어오는 경우만 누적
			{
				d[i][j] += d[i - 1][l];
			}
			d[i][j] %= mod;
		}
	}
	long long result = 0;
	for (int i = 0; i < 10; i++)
		result += d[n][i];
	cout << result % mod << '\n';
}