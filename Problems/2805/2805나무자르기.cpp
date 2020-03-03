#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

bool check(vector<long long>& a, long long m, long long h) // 절단기의 높이 h로 나무를 잘라서 m이상을 만들 수 있는지 확인하는 함수
{
	long long cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] - h > 0) // h 가 나무의 높이보다 높으면 잘리지 않음
		{
			cnt += a[i] - h;
		}
	}
	return cnt >= m; // 자른 나무의 길이의 합이 m이상이면 참
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;

	vector<long long> a(n);
	long long maxlen = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (maxlen < a[i])	maxlen = a[i];
	}

	long long left = 0;
	long long right = maxlen; // 나무 길이의 최댓값
	long long ans = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (check(a, m, mid)) // 현재 높이로 나무의 길이 m을 만들 수 있는지 확인
		{	
			if (ans < mid) 
				ans = mid; // 가능하다면 현재 절단기 높이 저장
			left = mid + 1; // 최댓값을 구해야하므로 더 높이 올릴 수 있는지 확인
		}
		else
		{
			right = mid - 1; // 불가능하다면 절단기 높이를 낮춤
		}
	}
	cout << ans << '\n';
}