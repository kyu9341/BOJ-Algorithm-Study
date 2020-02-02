#include<iostream>
#include<algorithm>
using namespace std;
int d[31]; // d[n] = d[n - 2] * 3 + d[n - 4] * 2 + d[n - 6] * 2 ... (n - 2i) >= 0
int main(void)
{
	int n;
	cin >> n;

	d[0] = 1; // 초기값 지정 (마지막 +2 역할)
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
		{
			d[i] += d[j] * 2;
		}
	}
	cout << d[n] << '\n';

}