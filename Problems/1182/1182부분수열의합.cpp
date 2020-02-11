#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int a[21];
int main(void)
{
	int n, s;
	int sum;
	
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	// n개로 이루어진 수열 -> 0 ~ (n - 1) 까지 확인
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) // 비트마스크 사용
	{
		sum = 0;
		for (int k = 0; k < n; k++) // 모든 경우를 확인
		{
			if (i & (1 << k)) // ex) i가 101 인경우 1, 100 만 통과
				sum += a[k]; // 모든 부분수열의 합을 구함
		}
		if (s == sum)
			ans++;
	}
	cout << ans << '\n';
}