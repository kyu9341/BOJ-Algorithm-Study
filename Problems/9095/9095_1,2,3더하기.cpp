#include<iostream>

using namespace std;
int sum123_top_down(int n);
int sum123_bottom_up(int n);

int d[11]; // n < 11, d[n] = n�� 1, 2, 3�� ������ ��Ÿ���� ����� ��

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	cin >> t; // testcase

	while (t--)
	{
		cin >> n;
		cout << sum123_top_down(n) << '\n';
	}
}

int sum123_top_down(int n)
{
	if (n <= 1) // d[0] = 1(������, ��� ���ڸ� 0���� ���), d[1] = 1
		return 1;
	if (n == 2) // 1 + 1, 2
		return 2;
	if (d[n] > 0) // �޸�Ǿ������� ����
		return d[n];
	else
	{		// d[n] = d[n - 1] + d[n - 2] + d[n - 3]
		d[n] = sum123_top_down(n - 1) + sum123_top_down(n - 2) + sum123_top_down(n - 3); 
	}
	return d[n];
}

int sum123_bottom_up(int n)
{
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		if (d[i] > 0)
			continue;
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
	return d[n];
}