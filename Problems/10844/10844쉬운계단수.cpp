#include<iostream>

using namespace std;
const long long mod = 1000000000;
// 점화식 d[i][j] = 길이가 i인 계단 수의 총 개수, 이전 수의 맨 마지막 수 = j
long long d[101][10];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int j = 1; j <= 9; j++)
		d[1][j] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			// d[i][j] = 0;
			if (j <= 8)
			{
				d[i][j] += d[i - 1][j + 1];
			}
			if (j >= 1)
			{
				d[i][j] += d[i - 1][j - 1];
			}
			 d[i][j] %= mod; // 미리 나머지로 바꿔주어야 정수 범위내에서 연산 가능
		}
	}
	long long result = 0;
	for (int j = 0; j <= 9; j++) // n의 모든 경우를 누적
		result += d[n][j];
	cout << result % mod << '\n';

}
