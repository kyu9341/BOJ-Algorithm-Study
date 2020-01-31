#include<iostream>

using namespace std;
int d[1001];
int p[10001];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i]; // Pi 입력

	for (int i = 1; i <= n; i++) d[i] = -1; // 모두 -1로 초기화 or 1000*10000으로 초기화 하여 최솟값을 구해도 무방
	d[0] = 0;

	for (int i = 1; i <= n; i++) // d[n] = min(d[n - i] + p[i]) (1 <= i <= n)
	{
		for (int j = 1; j <= i; j++)
		{
			if (d[i] == -1 || d[i] > d[i - j] + p[j]) // -1 즉, 아직 값이 정해지지 않았거나 더 작은 값이 생긴 경우
				d[i] = d[i - j] + p[j]; // d[i] 값 변경
		}
	}

	cout << d[n] << '\n';
}