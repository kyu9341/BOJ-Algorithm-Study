#include<iostream>
// 2×n 직사각형을 1x2와 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
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

// 2xn 타일링 문제에서 d[n - 2]인 경우가 두배가 된 것.
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