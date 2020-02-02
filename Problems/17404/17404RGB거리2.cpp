#include<iostream>
#include<algorithm>
using namespace std;
int d[1001][3]; // d[i][j] = i번째 집까지 모든 집을 칠하는 비용의 최솟값, j는 이번에 색칠할 집의 색깔
int rgb[1001][3];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			cin >> rgb[i][j];

	int ans = 1000 * 1000 + 1; // 모든 경우보다 큰 값

	for (int k = 0; k <= 2; k++) // 첫 번째 집의 색깔 k(1:red, 2:green, 3:blue)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (i == k)
				d[1][i] = rgb[1][i]; // 현재 색깔을 첫 번째 집 색깔로 고정
			else
				d[1][i] = 1000 * 1000 + 1;
		}

		for (int i = 2; i <= n; i++)
		{
			d[i][0] = min(d[i - 1][1], d[i - 1][2]) + rgb[i][0];
			d[i][1] = min(d[i - 1][0], d[i - 1][2]) + rgb[i][1];
			d[i][2] = min(d[i - 1][0], d[i - 1][1]) + rgb[i][2];
		}

		// 첫번째 집 색깔이 k인 경우 마지막 집은 k가 아닌 색깔이 가능
		for (int i = 0; i <= 2; i++)
		{
			if (i == k) continue; // k 인경우 건너뜀
			ans = min(ans, d[n][i]); // 나머지 경우의 최솟값을 구함
		}
		
	}

	cout << ans << '\n';
}