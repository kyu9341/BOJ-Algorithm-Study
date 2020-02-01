#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int d[1001]; // d[n] = a[1]...a[n] ������ a[n]�� ������ ���� ���� �κ� ������ ��
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i]; // �� ���� �ʱⰪ�� a[i]
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && d[i] < d[j] + a[i]) // �����ϴ� ����̸鼭 ���� �ε����� ������ ũ�ٸ�
			{
				d[i] = d[j] + a[i]; // d[i]�� �̾����� ������ ���� ������ ���� ���� ���� ����(���� �� BIS�� ���� ���� ����)
			}
		}
	}
	int maxSum = 0;
	for (int i = 1; i <= n; i++)
		maxSum = max(maxSum, d[i]);
	cout << maxSum << '\n';
}