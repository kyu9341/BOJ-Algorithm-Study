#include<iostream>
// LIS ����
using namespace std;
int a[1001];
int d[1001]; // d[i] = a[1], ... a[i] ���� ���� ��, a[i]�� ���� ���������� �ϴ� LIS�� ����

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // ������ ũ��
	cin >> n;

	for (int i = 1; i <= n; i++) // ���� �Է�
		cin >> a[i];
	d[1] = 1; // �ʱⰪ ���� ������ ũ�Ⱑ 1�̸� LIS�� 1
	int max = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = 1; // ��� d[i]�� �ʱⰪ�� 1
		for (int j = 1; j < i; j++)
		{										// ������ ������ ���� �� ũ�鼭
			if (d[i] < d[j] + 1 && a[i] > a[j]) // i���� ���� LIS�߿��� ���� �� LIS�� 1�� ���ϸ� d[i]
			{									
				d[i] = d[j] + 1;
			}
		}
		if (max < d[i]) // ��� d[i] �� �ִ��� ����
			max = d[i];
	}
	cout << max << '\n';
}