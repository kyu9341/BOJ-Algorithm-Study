#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 9901;
long long d[100001][3]; // d[i][j] = 2xi 배열에 사자를 배치하는 경우의 수, j는 이전 행의 사자 위치(없으면 인덱스 0)
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; //  N(1≤N≤100,000)
	cin >> n;
	d[1][0] = 1; // 세로 1칸에 사자가 없는 경우
	d[1][1] = 1; // 세로 1칸에 사자가 첫째 열에 있는 경우
	d[1][2] = 1; // 세로 1칸에 사자가 둘째 열에 있는 경우

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][1] + d[i - 1][2] + d[i - 1][0]; // 사자가 없는 경우에는 사자가 1열에 있거나 2열에 있거나 없는 경우 모두 가능
		d[i][1] = d[i - 1][2] + d[i - 1][0]; // 이전 행의 1열에 사자가 있다면 2열에 사자를 놓거나 놓지 않는 경우 가능
		d[i][2] = d[i - 1][1] + d[i - 1][0]; // 이전 행의 2열에 사자가 있다면 1열에 사자를 놓거나 놓지 않는 경우 가능

		d[i][0] %= mod;
		d[i][1] %= mod;
		d[i][2] %= mod;
	}

	cout << (d[n][0] + d[n][1] + d[n][2]) % mod << '\n';

}