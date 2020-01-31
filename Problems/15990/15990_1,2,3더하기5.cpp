#include<iostream>

using namespace std;
long long d[100001][4]; // d[i][j] = i�� 1, 2, 3�� ������ ��Ÿ���� ����� ��, �������� ����� ���� j
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
				d[i][1] = 1; // 1�� �����µ� 1�� ����� ���� 1��
		}
		if (i - 2 >= 0)
		{
			d[i][2] = d[i - 2][1] + d[i - 2][3];
			if (i == 2)
				d[i][2] = 1;  // 2�� �����µ� 2�� ����� ���� 2��
		}
		if (i - 3 >= 0)
		{
			d[i][3] = d[i - 3][1] + d[i - 3][2];
			if (i == 3)
				d[i][3] = 1; // 3���� �����µ� 3�� ����� ���� 3��
		}
		d[i][1] %= mod; // ���� ������ �ѱ� ���� ó��
		d[i][2] %= mod;
		d[i][3] %= mod;
	}
	return (d[n][1] + d[n][2] + d[n][3]) % mod;
}