#include<iostream>
#include<algorithm>

using namespace std;

pair<long long, long long> zeros(long long n)
{
	long long two = 0;
	long long five = 0;
	for (long long i = 5; i <= n; i *= 5) // 5의 개수 카운트
		five += n / i;
	for (long long i = 2; i <= n; i *= 2) // 2의 개수 카운트
		two += n / i;
	return {two, five};
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;

	pair<long long, long long> resM, resN, resNM;
	long long two = 0, five = 0;
	resM = zeros(m);
	resN = zeros(n);
	resNM = zeros(n - m);

	two = resN.first - resM.first - resNM.first; // n의 2의 개수에서 m과 (n-m)의 2의 개수를 빼줌
	five = resN.second - resM.second - resNM.second;  // n의 5의 개수에서 m과 (n-m)의 5의 개수를 빼줌

	cout << min(two, five) << '\n';
	return 0;
}

