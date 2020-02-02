#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int d[1001]; // d[n] = a[1]...a[n]���� a[n]���� ������ LIS
int d2[1001]; // d2[n] = a[n]���� �����ϴ� �����ϴ� �κм����� ����
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) // d[n] = a[n]���� ������ �����ϴ� �κм���
	{
		d[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	for (int i = n; i >= 1; i--)  // d[n] = a[n]���� �����ϴ� �����ϴ� �κм���
	{		 // a[n]���� �����ؾ��ϱ� ������ �ݴ�� ���ҽ�Ű�� ���Ѵ�
		d2[i] = 1;
		for (int j = i + 1; j <= n; j++) 
		{
			if (a[i] > a[j] && d2[i] < d2[j] + 1)
				d2[i] = d2[j] + 1;
		}
	}
	
	int result = 0;
	for (int i = 1; i <= n; i++)
		result = max(result, d[i] + d2[i] - 1); // n�� ���ļ� �ι� ������ ������ 1�����ش�
	cout << result << '\n';
}