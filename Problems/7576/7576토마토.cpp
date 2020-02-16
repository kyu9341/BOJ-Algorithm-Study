#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int a[1001][1001];
int d[1001][1001]; // 익은 토마토에서의 거리(날짜)
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


int main(void)
{
	int n, m;
	cin >> m >> n;

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			d[i][j] = -1; // 토마토가 익지 못하는 상황을 찾기 위해 -1로 초기화(0은 익은 토마토의 초기 위치)
			if (a[i][j] == 1)
			{
				q.push(make_pair(i, j)); // 익은 토마토를 큐에 넣어 bfs의 시작점으로 정한다.
				d[i][j] = 0; // 익은 토마토 초기 위치
			}
		}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) // 상자 내부
			{
				if (a[nx][ny] == 0 && d[nx][ny] == -1) // 안익은 토마토이고 방문하지 않은 경우
				{
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1; // 토마토의 초기 위치는 0, 다음 위치는 +1
				}

			}
		}
	}
	int ans = 0; // 모두 익는 일수
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (ans < d[i][j]) // 최댓값을 구함(모두 익는 날짜)
				ans = d[i][j]; 
		}
	
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && d[i][j] == -1) // 모든 토마토가 익을 수 없는 경우
				ans = -1;
		}

	cout << ans << '\n';
}