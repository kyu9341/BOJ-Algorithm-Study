#include <iostream>

using namespace std;
long long d[201][201];
long long mod = 1000000000;
int main(void)
{
	int n, k; // n이하의 정수 k개를 더해 n을 만드는 경우의 수
	cin >> n >> k;

    d[0][0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			for (int l = 0; l <= j; l++)
			{
				d[i][j] += d[i - 1][j - l]; // d[k][n] = sum(d[k - 1][n - L])
				d[i][j] %= mod;
			}
			
	cout << d[k][n] << '\n';
	
}