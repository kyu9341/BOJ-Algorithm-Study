#include<iostream>
#include<algorithm>
using namespace std;
int d[100001]; // d[i]는 i번째 수로 끝나는 연속합
int d2[100001]; // d[i]는 i번째 수부터 시작하는 연속합
int a[100001]; // 입력 수열
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1, j = 0; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) // i번째 수로 끝나는 최대 연속합을 구한다.
	{
		d[i] = a[i];
		if (d[i - 1] + a[i] > a[i]) //  i-1까지의 최대 연속합에 현재 수를 더한 것이 현재 수보다 더 큰지 비교
			d[i] = d[i - 1] + a[i];
		
	}

	for (int i = n; i >= 1; i--) // i번째 수로 시작하여 n으로 끝나는 최대 연속합을 구한다.
	{
		d2[i] = a[i];
		if (i == n)	continue; // i + 1은 접근하면 안되므로
		if (d2[i] < d2[i + 1] + a[i]) // i는 n - 1부터 감소하며 비교
			d2[i] = d2[i + 1] + a[i];

	}

	int ans = d[1];
	for(int i = 1; i <= n; i++)	// 수를 제거하지 않을 수도 있으므로 
		ans = max(ans, d2[i]);	// 제거하지 않는 경우 정답을 구해놓는다.
	   
	for (int i = 0; i <= n; i++)
		ans = max(ans, d[i - 1] + d2[i + 1]);
	cout << ans << '\n';
}