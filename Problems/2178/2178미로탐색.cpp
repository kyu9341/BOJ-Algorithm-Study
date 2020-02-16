#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
int a[101][101];
bool check[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int dist[101][101]; // (0, 0)에서부터의 거리
int n, m; // 미로의 행(세로), 열(가로)

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	dist[0][0] = 1;

	while (!q.empty())
	{
		x = q.front().first; // 현재 좌표
		y = q.front().second;
		q.pop(); // 좌표 저장 후 pop (bfs)

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i]; // 다음 좌표
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) // 미로의 범위 내에서
			{
				if (check[nx][ny] == false && a[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny)); // 방문할 때 push
					check[nx][ny] = true; // 방문 처리
					dist[nx][ny] = dist[x][y] + 1; // (0, 0)을 1로 시작하여 거리 계산
				}
			}
		}

	}
}

int main(void)
{
	cin >> n >> m;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < str.length(); j++)
			a[i][j] = int(str[j] - '0'); // 정수로 변환
	}
	bfs(0, 0);

	cout << dist[n - 1][m - 1] << '\n';

}