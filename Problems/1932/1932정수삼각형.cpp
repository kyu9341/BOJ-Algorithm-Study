#include<iostream>
#include<algorithm>
using namespace std;
int tri[501][501];
int d[501][501]; // d[i][j] = ũ�Ⱑ i�� �ﰢ���� �ִ밡 �Ǵ� ��ο� �ִ� ���� ��, j�� ���� �ε���
	// ��, d[i][j] = i�� j�� �� ���õǾ��� ��, �ִ� ��
int main(void)
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> tri[i][j];
	
	d[1][1] = tri[1][1]; // �ʱⰪ ����

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++) 
		{
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + tri[i][j]; // ���� ��ܰ� ���� ����� �� �� ū ���� ���� ���� ����
		}
	}

	int maxSum = 0;
	for (int i = 1; i <= n; i++)
	{
		maxSum = max(maxSum, d[n][i]);
	}
	cout << maxSum << '\n';
}