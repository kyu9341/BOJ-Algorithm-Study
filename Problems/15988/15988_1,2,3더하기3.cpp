#include <iostream>

using namespace std;
const long long mod = 1000000009;
long long d[1000001];
int sum123_bottom_up(int n);

int main(void)
{
	int t; // testcase
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		cout << sum123_bottom_up(n) << '\n';
	}
}

int sum123_bottom_up(int n)
{
	d[0] = 1; // 0 + 1, 0 + 2, 0 + 3 이 가능하므로 1로 초기화
	
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > 0)
			continue;
		d[i] += d[i - 1];
		if (i >= 2)
			d[i] += d[i - 2];
		if (i >= 3)
			d[i] += d[i - 3];
		d[i] %= mod;
	}

	return d[n] % mod;

}