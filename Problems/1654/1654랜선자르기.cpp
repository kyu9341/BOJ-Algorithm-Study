#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

bool check(vector<int>& a, int n, int l)
{
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		cnt += a[i] / l; // 가지고 있는 랜선을 길이 l로 자르면 몇 개를 만들 수 있는지 확인
	}
	return cnt >= n; // 만들 수 있는 랜선의 개수가 n이상이면 참
}

int main(void)
{
	int k, n;
	cin >> k >> n;

	vector<int> a(k);

	long long right = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		if (right < a[i])
			right = a[i]; // 랜선 길이의 최댓값
	}

	long long ans = 0;
	long long left = 1;
	
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (check(a, n, mid)) // 현재 길이로 n개의 랜선을 만들 수 있는지 확인
		{
			ans = mid; // 현재 길이를 저장하고
			left = mid + 1; // 더 큰 길이로 만들 수 있는지 확인
		}
		else // 현재 길이로 n개를 만들 수 없다면 길이를 줄여서 확인
		{
			right = mid - 1;
		}

	}

	cout << ans << '\n';

}