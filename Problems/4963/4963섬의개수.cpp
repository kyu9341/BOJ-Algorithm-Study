#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int a[50][50];
bool check[50][50];
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 }; // 상하좌우 대각선
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int w, h; // 너비, 높이


void dfs(int x, int y)
{
	check[x][y] = true; // 방문 처리
	
	for (int i = 0; i < 8; i++) // 상하좌우, 대각선 탐색 (8방)
	{
		int nx = x + dx[i]; // 다음 x좌표
		int ny = y + dy[i]; // 다음 y좌표

		if (nx >= 0 && ny >= 0 && nx < h && ny < w) // 지도의 범위 내부
		{
			if (a[nx][ny] == 1 && check[nx][ny] == false) // 다음 좌표가 육지이고 방문하지 않았다면
			{
				dfs(nx, ny);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> a[i][j];

		memset(check, false, sizeof(check)); // check 초기화

		int count = 0; // 연결요소의 개수
		for(int x = 0; x < h; x++)
			for (int y = 0; y < w; y++)
			{
				if (a[x][y] == 1 && check[x][y] == false) // 현재 좌표가 육지이고 방문하지 않은 경우
				{
					count++; // 연결 요소 카운트
					dfs(x, y);
				}
			}
		cout << count << '\n';
	}
}