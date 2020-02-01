#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int d[1001]; // d[n] = a[1]...a[n] 까지의 a[n]이 마지막 수인 증가 부분 수열의 합
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i]; // 각 값의 초기값은 a[i]
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && d[i] < d[j] + a[i]) // 증가하는 경우이면서 현재 인덱스의 값보다 크다면
			{
				d[i] = d[j] + a[i]; // d[i]에 이어지는 이전의 증가 수열에 현재 값을 더해 저장(가장 긴 BIS에 현재 값을 더함)
			}
		}
	}
	int maxSum = 0;
	for (int i = 1; i <= n; i++)
		maxSum = max(maxSum, d[i]);
	cout << maxSum << '\n';
}