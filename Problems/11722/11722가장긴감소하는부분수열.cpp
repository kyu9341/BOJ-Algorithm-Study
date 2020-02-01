#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int d[1001]; // d[n] = a[1]...a[n]에서 a[n]을 가장 마지막 수로 하는 감소하는 부분 수열의 개수
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		d[i] = 1; // 초기값은 모두 1(because 기본은 자기 자신 하나 1)
		for (int j = 1; j < i; j++)
		{
			if (a[i] < a[j] && d[i] < d[j] + 1) // 크기가 감소하면서 가장긴 LDS의 길이에 1을 더한 값이 d[i]보다 더 크면
				d[i] = d[j] + 1;
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
		result = max(result, d[i]);

	cout << result << '\n';
}