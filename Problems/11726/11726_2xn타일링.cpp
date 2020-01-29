#include<iostream>

using namespace std;
int d[1001] = { 0 }; // d[n] = 2xn ũ���� ���簢���� ä��� ����� ��
int tiling(int n) // top-down ���
{
	if (n <= 2) // n�� d[1] = 1, d[2] = 2�̹Ƿ�
		return n;
	if (d[n] > 0) // �̹� ���� ���
		return d[n];
	else
	{
		d[n] = tiling(n - 1) + tiling(n - 2); // d[n] = d[n - 1] + d[n - 2]
		d[n] %= 10007; // 10007�� ���� ������ ���
	}
	return d[n];
}
int tiling1(int n) // bottom-up ���
{
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		if (d[i] > 0)
			continue;
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 10007; // 10007�� ���� ������ ���
	}
	return d[n];
}

int main(void)
{
	int n;
	cin >> n;

	cout << tiling(n) << '\n';
}