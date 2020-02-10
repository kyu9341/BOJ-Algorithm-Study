#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int ans = 0;
void go(int n, vector<int>& t, vector<int>& p, int day, int sum)
{
	if (day == n + 1)
	{
		if (ans < sum) ans = sum; // 금액의 최댓값
		return;
	}
	if (day > n + 1) return; // 불가능한 경우
	
	go(n, t, p, day + t[day], sum + p[day]); // day일에 상담을 하는 경우
	go(n, t, p, day + 1, sum); // 하지 않는 경우
}
int main(void)
{
	int n;
	cin >> n;
	
	vector<int> t(n + 1); // 상담 완료에 걸리는 기간
	vector<int> p(n + 1); // 금액

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	go(n, t, p, 1, 0);
	cout << ans << '\n';
}