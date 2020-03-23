#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>

using namespace std;
const int MAX = 500;
int n, m;
int a[MAX + 1][MAX + 1];
bool check[MAX + 1][MAX + 1];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0 , 0 };
int ans = 0;

void dfs(int x, int y, int sum, int index) // 한 점에서 시작하여 4개의 칸을 확인하는 경우 모두 확인
{
	check[x][y] = true;
	if (index == 4)
	{
		if (sum > ans) ans = sum; // 네 칸의 합의 최댓값
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (check[nx][ny] == false)
			{
				dfs(nx, ny, sum + a[x][y], index + 1);
				check[nx][ny] = false; // 방문 처리 해제
			}
		}
	}
	check[x][y] = false; // 시작점 방문 처리 해제
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, 0, 0);
			// dfs로 구할 수 없는 한 가지 경우 처리
			if (j + 2 < m) //  ㅗ, ㅜ 모양 처리
			{
				int tmp1 = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0)
				{
					int tmp2 = tmp1 + a[i - 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
				if (i + 1 < n)
				{
					int tmp2 = tmp1 + a[i + 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
			}
			if (i + 2 < n) // ㅓ, ㅏ 모양 처리
			{
				int tmp1 = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j - 1 >= 0)
				{
					int tmp2 = tmp1 + a[i + 1][j - 1];
					if (ans < tmp2) ans = tmp2;
				}
				if (j + 1 < m)
				{
					int tmp2 = tmp1 + a[i + 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
			}
		}

	cout << ans << '\n';
}