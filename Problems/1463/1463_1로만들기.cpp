#include<iostream>

using namespace std;
int d[1000001]; // d[n] : n을 1로 만드는 최소 연산 횟수

int go(int n) // top-down 방식 구현
{
	if (n == 1) // 1을 만든 경우 d[1] = 0
		return 0;
	if (d[n] > 0) // 이미 수행했던 연산인 경우
		return d[n]; // 메모이제이션
	else
	{
		d[n] = go(n - 1) + 1; // 최솟값을 더 편하게 구하기 위해 먼저 처리
		if (n % 2 == 0) // 2로 나누어 떨어지는 경우
		{
			int temp = go(n / 2) + 1;
			if (d[n] > temp) d[n] = temp; // 새로운 방식이 더 적은 연산을 필요로 하면 바꿔줌
		}
		if (n % 3 == 0)
		{
			int temp = go(n / 3) + 1;
			if (d[n] > temp) d[n] = temp;
		}
	}
	return d[n];
}

int go1(int n) // bottom-up 방식
{
	d[1] = 0; // 초기값 지정
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