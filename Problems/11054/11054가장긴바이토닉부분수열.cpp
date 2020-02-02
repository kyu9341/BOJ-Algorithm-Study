#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int d[1001]; // d[n] = a[1]...a[n]에서 a[n]으로 끝나는 LIS
int d2[1001]; // d2[n] = a[n]에서 시작하는 감소하는 부분수열의 길이
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) // d[n] = a[n]으로 끝나는 증가하는 부분수열
	{
		d[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	for (int i = n; i >= 1; i--)  // d[n] = a[n]으로 시작하는 감소하는 부분수열
	{		 // a[n]으로 시작해야하기 때문에 반대로 감소시키며 비교한다
		d2[i] = 1;
		for (int j = i + 1; j <= n; j++) 
		{
			if (a[i] > a[j] && d2[i] < d2[j] + 1)
				d2[i] = d2[j] + 1;
		}
	}
	
	int result = 0;
	for (int i = 1; i <= n; i++)
		result = max(result, d[i] + d2[i] - 1); // n이 겹쳐서 두번 나오기 때문에 1을빼준다
	cout << result << '\n';
}