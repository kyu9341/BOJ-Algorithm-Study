#include<iostream>
using namespace std;
long long d[91][2]; // d[i][j] = 이전 수가 j인 i자리 이친수의 개수

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	d[1][1] = 1;
	d[1][0] = 0; // 0으로 시작하는 수는 이친수가 아님
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[n][0] + d[n][1] << '\n';
}