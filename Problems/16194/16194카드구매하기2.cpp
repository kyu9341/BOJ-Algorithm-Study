#include<iostream>

using namespace std;
int d[1001];
int p[10001];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i]; // Pi �Է�

	for (int i = 1; i <= n; i++) d[i] = -1; // ��� -1�� �ʱ�ȭ or 1000*10000���� �ʱ�ȭ �Ͽ� �ּڰ��� ���ص� ����
	d[0] = 0;

	for (int i = 1; i <= n; i++) // d[n] = min(d[n - i] + p[i]) (1 <= i <= n)
	{
		for (int j = 1; j <= i; j++)
		{
			if (d[i] == -1 || d[i] > d[i - j] + p[j]) // -1 ��, ���� ���� �������� �ʾҰų� �� ���� ���� ���� ���
				d[i] = d[i - j] + p[j]; // d[i] �� ����
		}
	}

	cout << d[n] << '\n';
}