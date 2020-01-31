#include<iostream>

using namespace std;
const long long mod = 1000000000;
// ��ȭ�� d[i][j] = ���̰� i�� ��� ���� �� ����, ���� ���� �� ������ �� = j
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
			 d[i][j] %= mod; // �̸� �������� �ٲ��־�� ���� ���������� ���� ����
		}
	}
	long long result = 0;
	for (int j = 0; j <= 9; j++) // n�� ��� ��츦 ����
		result += d[n][j];
	cout << result % mod << '\n';

}
