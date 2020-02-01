
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int score[2][100002];
int d[3][100001]; // d[i][j] = 2j 까지의 점수의 최대값 (i = 0 인 경우는 스티커를 떼지 않는 경우, i = 1, i = 2인 경우는 이번에 뗄 스티커의 행)
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; //testcase
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> score[i][j]; // 입력

		for (int j = 1; j <= n; j++)
		{
			d[0][j] = max({ d[0][j - 1], d[1][j - 1], d[2][j - 1] }); // 이번 열에 아무것도 떼지 않은 경우
			d[1][j] = max({ d[0][j - 1], d[2][j - 1] }) + score[1][j]; // 이번 열에 1행의 스티커를 떼는 경우
			d[2][j] = max({ d[0][j - 1], d[1][j - 1] }) + score[0][j]; // 이번 열에 2행의 스티커를 떼는 경우			
		}

		cout << max({ d[0][n], d[1][n], d[2][n] }) << '\n';

	}
}