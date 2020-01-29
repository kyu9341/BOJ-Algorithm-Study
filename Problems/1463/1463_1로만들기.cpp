#include<iostream>

using namespace std;
int d[1000001]; // d[n] : n�� 1�� ����� �ּ� ���� Ƚ��

int go(int n) // top-down ��� ����
{
	if (n == 1) // 1�� ���� ��� d[1] = 0
		return 0;
	if (d[n] > 0) // �̹� �����ߴ� ������ ���
		return d[n]; // �޸������̼�
	else
	{
		d[n] = go(n - 1) + 1; // �ּڰ��� �� ���ϰ� ���ϱ� ���� ���� ó��
		if (n % 2 == 0) // 2�� ������ �������� ���
		{
			int temp = go(n / 2) + 1;
			if (d[n] > temp) d[n] = temp; // ���ο� ����� �� ���� ������ �ʿ�� �ϸ� �ٲ���
		}
		if (n % 3 == 0)
		{
			int temp = go(n / 3) + 1;
			if (d[n] > temp) d[n] = temp;
		}
	}
	return d[n];
}

int go1(int n) // bottom-up ���
{
	d[1] = 0; // �ʱⰪ ����
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
			d[i] = d[i / 2] + 1;
		else if (i % 3 == 0 && d[i] > d[i / 3] + 1)
			d[i] = d[i / 3] + 1;
	}
	return d[n];
}

int main(void)
{
	int x; 
	cin >> x;

	cout << go(x) << '\n';
}