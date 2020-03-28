#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, b, c; // 100만 * 100만이 최대이므로 long long
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;
	long long ans = n; // 총 감독관은 무조건 1명씩
	for (int i = 0; i < n; i++)
	{
		a[i] -= b;
		if (a[i] <= 0) continue; // 총 감독관 1명으로 모두 감시 가능한 경우
		long long s = a[i] / c;
		long long r = a[i] % c;

		ans += r == 0 ? s : s + 1; // 나머지가 0이 아니면 1명 추가
	}

	cout << ans << '\n';
}