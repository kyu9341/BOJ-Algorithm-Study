#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int dx[] = { -2, -2, 0, 0, 2, 2 }; // (x, y)로 이동 가능한 상대 좌표
int dy[] = { -1, 1, -2, 2, -1, 1 };
bool check[201][201];
int dist[201][201];

int main(void)
{
	int n;
	cin >> n;

	int sr, sc, er, ec; // 시작점, 도착점
	cin >> sr >> sc >> er >> ec;

	memset(dist, -1, sizeof(dist)); // 거리를 모두 -1로 초기화

	queue<pair<int, int>> q;
	q.push(make_pair(sr, sc)); // 시작 좌표 push
	check[sr][sc] = true;
	dist[sr][sc] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) // 이동 가능한 모든 경우 확인
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) // 범위 내에서
			{
				if (check[nx][ny] == false) // 아직 확인하지 않은 경우
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1; // 다음 좌표 push 후 거리 추가
				}
			}
		}

	}

	cout << dist[er][ec] << '\n';
}