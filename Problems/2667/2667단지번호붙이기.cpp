#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>

using namespace std;

int d[25][25]; // 단지 번호를 기록할 배열
int a[25][25]; // 집의 유무를 기록할 배열
int dx[] = { 0, 0, 1, -1 }; // 상하좌우 이동 좌표
int dy[] = { 1, -1, 0, 0 };
int n; // 지도의 크기

void dfs(int x, int y, int count)
{
	d[x][y] = count; // 현재 좌표의 단지 번호를 붙임

	for (int i = 0; i < 4; i++) // 상하좌우 탐색
	{
		int nx = x + dx[i];
		int ny = y + dy[i]; 

		if (nx >= 0 && ny >= 0 && nx < n && ny < n) // 지도의 범위 내에서
		{
			if (a[nx][ny] == 1 && d[nx][ny] == 0) // 다음번 좌표에 집이 있고, 아직 탐색하지 않은 경우(단지 번호가 안붙어있는 경우)
			{
				dfs(nx, ny, count);
			}
		}
	}

}

void bfs(int x, int y, int count)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = count; // 현재 좌표에 단지번호 붙이기
	
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop(); // 맨 앞 좌표 저장후 pop

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n)
			{
				if (a[nx][ny] == 1 && d[nx][ny] == 0) // 다음 좌표가 육지이고 아직 방문하지 않은 경우
				{
					q.push(make_pair(nx, ny)); // 다음 좌표 push
					d[nx][ny] = count; // 방문처리 and 단지번호 붙이기
				}
			}
		}
	}

}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%1d", &a[i][j]); // 한자리씩 입력


	int count = 0; // 단지 번호(연결 요소의 개수)
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1 && d[i][j] == 0) // 현재 좌표에 집이 있고 탐색되지 않은 경우
			{

				bfs(i, j, count + 1);
				// dfs(i, j, count + 1);
				count++;
			}
				
		}

	int ans[25 * 25] = { 0 };

	cout << count << '\n';

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ans[d[i][j]]++; // 단지번호 별 주택의 개수 파악
		}

	sort(ans + 1, ans + count + 1); // 단지 번호를 1부터 붙였으므로


	for (int i = 1; i <= count; i++)
		cout << ans[i] << '\n';

}