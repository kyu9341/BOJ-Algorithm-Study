#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 }; // x, y의 상대적 위치
int dy[] = { 1, 2, 2, 1, -1, -2, -2 ,-1 };
bool check[301][301];
int d[301][301]; // 이동 횟수
int n; // 한 변의 길이

bool isInside(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < n)
		return true;
	else
		return false;
}

void bfs(int x, int y)
{
	memset(d, 0, sizeof(d)); // d, check 배열 초기화
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 0;
	check[x][y] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) // 8방향 모두 탐색
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny)) // 체스판 내부인지 확인
			{
				if (check[nx][ny] == false)
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = true; // 방문 처리
					d[nx][ny] = d[x][y] + 1; // 이동 횟수 추가
				}
			}
		}
	}
}
int main(void)
{
	int t; // test case
	cin >> t;

	while (t--)
	{
		cin >> n;
		int sx, sy, ex, ey;
		cin >> sx >> sy; // 시작 위치
		cin >> ex >> ey; // 마지막 위치

		bfs(sx, sy);

		cout << d[ex][ey] << '\n';

	}
}