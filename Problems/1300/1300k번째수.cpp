#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<climits>

using namespace std;
long long n, k;

long long go(long long mid) // mid의 인덱스를 구하는 함수
{
	long long cnt = 0;
	for (long long i = 1; i <= n; i++)
	{ // 현재 원소(mid)보다 작거나 같은 수의 개수를 count
		cnt += min(n, mid / i);
	}
	return cnt; // mid의 인덱스
}

int main(void)
{
	cin >> n >> k;

	long long left = 1;
	long long right = n * n;
	long long ans = 1;
	while (left <= right)
	{
		long long mid = (left + right) / 2; // 현재 원소

		if (go(mid) >= k) // 현재 원소의 인덱스가 더 크다면
		{
			ans = mid;
			right = mid - 1; // 현재 원소를 감소시켜 확인
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans << '\n';
}