#include<iostream>
// 2��n ���簢���� 1x2�� 2��1�� 2��2 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
using namespace std;
int d[1001];
int tiling_bottom_up(int n);
int tiling_top_down(int n);

int main(void)
{
	int n;
	cin >> n;
	
	cout << tiling_bottom_up(n) <<'\n';

}

// 2xn Ÿ�ϸ� �������� d[n - 2]�� ��찡 �ι谡 �� ��.
int tiling_bottom_up(int n)
{
	d[1] = 1;
	d[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		if (d[i] > 0)
			continue;
		d[i] = d[i - 1] + d[i - 2] * 2; // d[n] = d[n - 1] + d[n - 2]*2
		d[i] %= 10007;
	}
	return d[n];
}

int tiling_top_down(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;

	if (d[n] > 0)
		return d[n];
	else
	{
		d[n] = d[n - 1] + d[n - 2] * 2;
		d[n] %= 10007;
	}
	return d[n];
}