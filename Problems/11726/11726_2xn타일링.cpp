#include<iostream>

using namespace std;
int d[1001] = { 0 }; // d[n] = 2xn 크기의 직사각형을 채우는 방법의 수
int tiling(int n) // top-down 방식
{
	if (n <= 2) // n이 d[1] = 1, d[2] = 2이므로
		return n;
	if (d[n] > 0) // 이미 구한 경우
		return d[n];
	else
	{
		d[n] = tiling(n - 1) + tiling(n - 2); // d[n] = d[n - 1] + d[n - 2]
		d[n] %= 10007; // 10007로 나눈 나머지 출력
	}
	return d[n];
}
int tiling1(int n) // bottom-up 방식
{
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		if (d[i] > 0)
			continue;
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 10007; // 10007로 나눈 나머지 출력
	}
	return d[n];
}

int main(void)
{
	int n;
	cin >> n;

	cout << tiling(n) << '\n';
}