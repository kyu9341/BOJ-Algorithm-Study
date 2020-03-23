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

void dfs(int x, int y, int sum, int index) // �� ������ �����Ͽ� 4���� ĭ�� Ȯ���ϴ� ��� ��� Ȯ��
{
	check[x][y] = true;
	if (index == 4)
	{
		if (sum > ans) ans = sum; // �� ĭ�� ���� �ִ�
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
				check[nx][ny] = false; // �湮 ó�� ����
			}
		}
	}
	check[x][y] = false; // ������ �湮 ó�� ����
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
			// dfs�� ���� �� ���� �� ���� ��� ó��
			if (j + 2 < m) //  ��, �� ��� ó��
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
			if (i + 2 < n) // ��, �� ��� ó��
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