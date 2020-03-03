#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

bool check(vector<int>& a, int c, int dist) // 인접한 공유기 사이의 거리가 현재 간격(dist)이상인 경우가 c이상인지 판별하는 함수
{
	int cnt = 1; // 가능한 간격 + 1개가 공유기의 개수
	int last = a[0];
	for(int house : a)
	{
		if (house - last >= dist) // 직전에 공유기를 배치했던 집과 거리 비교
		{
			cnt++;
			last = house; // 공유기를 배치한 이전 집을 저장
		}
	}
	return cnt >= c; // 현재 인접한 공유기 사이의 거리가 dist이상인 경우가 c개 이상이면 참
}

int main(void)
{
	int n, c;
	cin >> n >> c;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end()); // 오른차순 정렬
	
	int right = a[n - 1] - a[0]; // 가장 멀리 떨어진 두 집의 차이
	int left = 1;
	int ans = 1;

	while (left <= right)
	{
		int mid = (left + right) / 2; // 인접한 두 공유기의 거리
		if (check(a, c, mid))
		{
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans << '\n';
}