#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++)
	{	// start는 *10씩 증가하므로 10, 100, 1000 .. (자릿수의 시작)
		int end = start * 10 - 1; // end는 99, 999, 9999 ... (자릿수의 마지막)
		if (end > n) // 입력 수보다 커지면
			end = n;
		ans += (long long)(end - start + 1) * len; // 자릿수의 개수에 자릿수를 곱함
	}
	cout << ans << '\n';
}