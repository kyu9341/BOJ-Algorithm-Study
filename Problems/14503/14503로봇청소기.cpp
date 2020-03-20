#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;
int a[51][51];
int dx[] = { -1, 0, 1, 0 }; // 0  : 북, 1 : 서, 2 : 남, 3 : 동
int dy[] = { 0, 1, 0,  -1 };
int n, m;
int ans = 0; // 청소기가 있는 칸은 항상 빈칸

int calc_dir(int dir, int rotation) // 청소기의 회전
{
	int res = dir + rotation;
	if (res > 3) res -= 4;
	if(res < 0) res += 4;
	return res;
}
void go(int x, int y, int dir)
{
	if (a[x][y] == 0) // 청소하지 않았다면 
	{
		a[x][y] = 2; // 청소
		ans++; // 카운트
	}

	int cnt = 4;
	while (cnt--) // 4방향 확인
	{
		dir = calc_dir(dir, -1); // 왼쪽으로 회전
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (a[nx][ny] == 0) // 빈칸이라면 청소
			{
				go(nx, ny, dir);
				return; // 다음 칸으로 넘어간 이후 나머지 방향은 검사 x
			}
		}
	}// 검사 끝

	// 네 방향 모두 청소가 이미 되어있거나 벽인 경우
	int rear = calc_dir(dir, -2); // 후진 방향 설정
	int nx = x + dx[rear];
	int ny = y + dy[rear];
	if (nx >= 0 && ny >= 0 && nx < n && ny < m)
	{
		if (a[nx][ny] == 1) // 후진도 못한다면
		{
			cout << ans << '\n';
			exit(0);
		}
		else // 후진한다
		{
			go(nx, ny, dir); // 방향은 유지
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	int sx, sy, dir;
	cin >> sx >> sy >> dir;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	go(sx, sy, dir);

}