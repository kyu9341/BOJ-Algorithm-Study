#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<deque>
#include<cstdio>

using namespace std;
const int MAX = 100;
int a[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main(void)
{
	int m, n; // m : 가로, n : 세로
	cin >> m >> n;
	cin.ignore();

	memset(dist, -1, sizeof(dist)); // -1로 초기화

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			a[i][j] = str[j] - '0';
	}

	deque<pair<int, int>> dq; // 덱 사용
	dq.push_back(make_pair(0, 0)); // 초기 위치
	dist[0][0] = 0;

	while (!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) // 범위 내에서
			{
				if (dist[nx][ny] == -1 && a[nx][ny] == 0) // 방문하지 않은 미로이고(-1) 빈 방인 경우(0)
				{
					dq.push_front(make_pair(nx, ny)); // 덱의 맨 앞에 push (빈 방이 우선순위)
					dist[nx][ny] = dist[x][y]; // 부순 벽의 개수는 유지
				}
				if (dist[nx][ny] == -1 && a[nx][ny] == 1) // 방문하지 않은 미로이고(-1) 벽인 경우(1)
				{
					dq.push_back(make_pair(nx, ny)); // 덱의 맨 뒤에 push
					dist[nx][ny] = dist[x][y] + 1; // 부순 벽의 개수 + 1
				}
			}
		}
	}
	cout << dist[n - 1][m - 1] << '\n';

}