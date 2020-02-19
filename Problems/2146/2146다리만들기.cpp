#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int a[101][101];
int check[101][101]; // 0 : 방문 안함, 1 ~ (n - 1) : cnt 번 째 육지
int dist[101][101] = { 0 };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n; // 지도의 크기

void dfs(int x, int y, int cnt) // 연결된 육지를 그룹으로 지정
{
	check[x][y] = cnt; // 몇 번째 육지인지 저장
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if (check[nx][ny] == 0 && a[nx][ny] == 1) // 육지이고 아직 방문하지 않은 경우
			{ 
				dfs(nx, ny, cnt);
			}
		}
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == 0 && a[i][j] == 1) // 육지이고 아직 방문하지 않은 경우
			{
				dfs(i, j, ++cnt); // 각 육지에 번호를 붙임
			}
		}
	}
		
	int ans = 10001;
	for (int k = 1; k <= cnt; k++) // 각 섬에서 나머지 모든 섬까지의 거리의 최솟값을 구한다.
	{
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = -1; // -1로 초기화
				if (check[i][j] == k) // k번째 섬 확인
				{
					q.push(make_pair(i, j)); // 이번 섬의 모든 위치에서 탐색
					dist[i][j] = 0; // 이번(k번째) 섬은 거리를 0으로 설정
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
				if (nx >= 0 && ny >= 0 && nx < n && ny < n)
				{
					if (dist[nx][ny] == -1) // 현재 k섬이 아닌 곳이라면
					{
						dist[nx][ny] = dist[x][y] + 1; //  k섬에서 떨어진 거리를 구함
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
				
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (check[i][j] != k && check[i][j] != 0) // 현재 섬이 아니고 바다도 아닌 경우(즉, 다른 섬인 경우)
				{
					if (dist[i][j] - 1 < ans) // 거리의 최솟값을 구한다.
						ans = dist[i][j] - 1; // 섬까지의 거리이므로 1을 뺀다.(다리의 길이를 구하는 것이므로)
				}

			}
	}

	cout << ans << '\n';

}