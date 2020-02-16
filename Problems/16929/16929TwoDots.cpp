#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
char color[50][50];
bool check[50][50];
int dist[50][50]; // 시작점부터 이동한 거리
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, m; // 게임판의 크기

bool dfs(int x, int y, int cnt)
{
	if (check[x][y]) // 이미 방문했던 노드인데
	{
		if (cnt - dist[x][y] >= 4) // 이동 횟수에서 현재 위치에 저장된 시작점과의 거리 차가 4 이상 = 싸이클
			return true;
		else
			return false;
	}
		
	check[x][y] = true;
	dist[x][y] = cnt; // 현재 x,y가 시작점에서 몇번 이동했는지 저장, 시작점은 0

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (color[nx][ny] == color[x][y]) // 같은 색깔의 점인 경우(방문여부는 관계x)
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