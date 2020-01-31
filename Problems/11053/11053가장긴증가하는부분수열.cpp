#include<iostream>
// LIS 문제
using namespace std;
int a[1001];
int d[1001]; // d[i] = a[1], ... a[i] 까지 있을 때, a[i]를 가장 마지막으로 하는 LIS의 길이

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 수열의 크기
	cin >> n;

	for (int i = 1; i <= n; i++) // 수열 입력
		cin >> a[i];
	d[1] = 1; // 초기값 지정 수열의 크기가 1이면 LIS는 1
	int max = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = 1; // 모든 d[i]의 초기값은 1
		for (int j = 1; j < i; j++)
		{										// 수열의 마지막 항이 더 크면서
			if (d[i] < d[j] + 1 && a[i] > a[j]) // i보다 작은 LIS중에서 가장 긴 LIS에 1을 더하면 d[i]
			{									
				d[i] = d[j] + 1;
			}
		}
		if (max < d[i]) // 모든 d[i] 중 최댓값이 정답
			max = d[i];
	}
	cout << max << '\n';
}