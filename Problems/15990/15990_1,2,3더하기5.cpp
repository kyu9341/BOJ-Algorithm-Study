#include<iostream>

using namespace std;
long long d[100001][4]; // d[i][j] = i를 1, 2, 3의 합으로 나타내는 방법의 수, 마지막에 사용한 수는 j
const long long mod = 1000000009;
int sum123_bottom_up(int);
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		cout << sum123_bottom_up(n) << '\n';
	}
}

int sum123_bottom_up(int n)
{	
	for (int i = 1; i <= n; i++)
	{
		if (i - 1 >= 0)
		{
			d[i][1] = d[i - 1][2] + d[i - 1][3];
			if (i == 1)
				d[i][1] = 1; // 1로 끝나는데 1을 만드는 경우는 1뿐
		}
		if (i - 2 >= 0)
		{
			d[i][2] = d[i - 2][1] + d[i - 2][3];
			if (i == 2)
				d[i][2] = 1;  // 2로 끝나는데 2을 만드는 경우는 2뿐
		}
		if (i - 3 >= 0)
		{
			d[i][3] = d[i - 3][1] + d[i - 3][2];
			if (i == 3)
				d[i][3] = 1; // 3으로 끝나는데 3을 만드는 경우는 3뿐
		}
		d[i][1] %= mod; // 정수 범위를 넘기 전에 처리
		d[i][2] %= mod;
		d[i][3] %= mod;
	}
	return (d[n][1] + d[n][2] + d[n][3]) % mod;
}