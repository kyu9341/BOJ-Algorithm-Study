#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int d[1001]; // d[n] = a[1]...a[n]���� a[n]�� ���� ������ ���� �ϴ� �����ϴ� �κ� ������ ����
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		d[i] = 1; // �ʱⰪ�� ��� 1(because �⺻�� �ڱ� �ڽ� �ϳ� 1)
		for (int j = 1; j < i; j++)
		{
			if (a[i] < a[j] && d[i] < d[j] + 1) // ũ�Ⱑ �����ϸ鼭 ����� LDS�� ���̿� 1�� ���� ���� d[i]���� �� ũ��
				d[i] = d[j] + 1;
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
		result = max(result, d[i]);

	cout << result << '\n';
}