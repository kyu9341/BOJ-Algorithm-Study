#include<iostream>

using namespace std;
int a[100001];
int d[100001]; // d[i] = i��° ���� ������ ���� ū ������

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[1] = a[1]; // �ʱⰪ ���� 

	int max = d[1];

	for (int i = 2; i <= n; i++)
	{
		if (a[i] > d[i - 1] + a[i]) // ���� ������ ���� �̾����� �����հ��� �հ� ��
			d[i] = a[i];			// �� ū ���� d[i]�� ����
		else
			d[i] = d[i - 1] + a[i];

		if (d[i] > max)				// d[i] �� �ִ��� ����
			max = d[i];
	}
	cout << max << '\n';
}