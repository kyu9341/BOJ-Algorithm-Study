#include<iostream>
using namespace std;
const int mod = 10007;
long long d[1001][10]; // d[i][j] = ���� ���� j�� i�ڸ� ������ ���� ����
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++) // ���ڸ� ���� ��� 1�� �ʱ�ȭ
		d[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int l = j; l <= 9; l++) // j ���� ũ�ų� ���� ���� ������ ��츸 ����
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