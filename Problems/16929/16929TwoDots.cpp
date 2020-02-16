#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
char color[50][50];
bool check[50][50];
int dist[50][50]; // ���������� �̵��� �Ÿ�
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, m; // �������� ũ��

bool dfs(int x, int y, int cnt)
{
	if (check[x][y]) // �̹� �湮�ߴ� ����ε�
	{
		if (cnt - dist[x][y] >= 4) // �̵� Ƚ������ ���� ��ġ�� ����� ���������� �Ÿ� ���� 4 �̻� = ����Ŭ
			return true;
		else
			return false;
	}
		
	check[x][y] = true;
	dist[x][y] = cnt; // ���� x,y�� ���������� ��� �̵��ߴ��� ����, �������� 0

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (color[nx][ny] == color[x][y]) // ���� ������ ���� ���(�湮���δ� ����x)
			{
				if (dfs(nx, ny, cnt + 1))
					return true;
			}
		}
	}
	return false;
}

int main(void)
{
	cin >> n >> m;
	
	cin.ignore();
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		for (int j = 0; j < m; j++)
		{
			color[i][j] = str[j];
		}
	}
		
	string ans = "No";
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (check[i][j] == false)
			{
				if (dfs(i, j, 0))
					ans = "Yes";
			}
		}
	cout << ans << '\n';
}