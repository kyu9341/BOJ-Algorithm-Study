#include<iostream>
#include<algorithm>
using namespace std;

int rgb[1001][3];
int d[1001][3]; // d[i][j] = i번 집을 색 j로 칠했을 때, 1~i번 집을 칠하는 비용의 최솟값

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) // 각 집의 색깔별 비용 입력
		for (int j = 0; j < 3; j++)
			cin >> rgb[i][j];

	for (int i = 1; i <= n; i++) // 현재까지의 최소 비용에 현재 색깔 비용을 추가
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + rgb[i][0]; // r의 앞에 올 수 있는 것은 g, b
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + rgb[i][1]; // g의 앞에 올 수 있는 것은 r, b
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + rgb[i][2]; // b의 앞에 올 수 있는 것은 r, g
	}

	cout << min({ d[n][0], d[n][1], d[n][2] }) << '\n';
}