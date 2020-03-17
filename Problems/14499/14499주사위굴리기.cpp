#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
int a[21][21];
int dice[3][3];
int n, m, k;

bool check(int x, int y) // 현재 x,y가 범위에 속하는지 확인
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return true;
	else return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x, y;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	vector<int> cmd(k); // 명령어 저장
	for (int i = 0; i < k; i++)
		cin >> cmd[i];

	// 주사위의 6면
	int bottom = 0;
	int top = 0;
	int north = 0;
	int south = 0;
	int east = 0;
	int west = 0;

	for (int i = 0; i < k; i++)
	{
		int nx, ny;
		switch (cmd[i])
		{
		case 1: // 동쪽으로 이동하는 경우
			nx = x; // 다음 좌표
			ny = y + 1;
			if (check(nx, ny))
			{ // 주사위의 각 면 이동
				int temp = bottom;
				bottom = east;
				east = top;
				top = west;
				west = temp;
				if (a[nx][ny] == 0) // 지도의 칸이 0인 경우
					a[nx][ny] = bottom; // 주사위의 바닥면이 복사
				else
				{
					bottom = a[nx][ny]; // 0이 아니면 주사위의 바닥면으로 복사
					a[nx][ny] = 0; // 지도의 칸은 0으로 변경
				}
			}
			else continue; // 범위를 벗어난 경우 해당 명령 무시
			x = nx;
			y = ny;
			break;
		case 2: // 서쪽으로 이동하는 경우
			nx = x;
			ny = y - 1;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = west;
				west = top;
				top = east;
				east = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		case 3: // 북쪽으로 이동하는 경우
			nx = x - 1;
			ny = y;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = north;
				north = top;
				top = south;
				south = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		case 4: // 남쪽으로 이동하는 경우
			nx = x + 1;
			ny = y;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = south;
				south = top;
				top = north;
				north = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		}
		cout << top << '\n'; // 윗면 출력

	}
	
}