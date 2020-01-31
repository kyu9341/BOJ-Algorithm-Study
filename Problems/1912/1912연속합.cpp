#include<iostream>

using namespace std;
int a[100001];
int d[100001]; // d[i] = i번째 수로 끝나는 가장 큰 연속합

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[1] = a[1]; // 초기값 지정 

	int max = d[1];

	for (int i = 2; i <= n; i++)
	{
		if (a[i] > d[i - 1] + a[i]) // 현재 수열의 값과 이어지는 연속합과의 합과 비교
			d[i] = a[i];			// 더 큰 값을 d[i]에 저장
		else
			d[i] = d[i - 1] + a[i];

		if (d[i] > max)				// d[i] 의 최댓값이 정답
			max = d[i];
	}
	cout << max << '\n';
}