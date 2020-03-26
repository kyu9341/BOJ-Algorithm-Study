#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
const int MAX = 40;
int n, m, k;
int a[40][40];
int sticker[10][10];

void attach(int i, int j, int row, int col) // 스티커를 노트북에 붙이는 함수
{
	for (int x = i; x < i + row; x++)
		for (int y = j; y < j + col; y++)
		{
			if(a[x][y] == 0)
				a[x][y] = sticker[x - i][y - j]; // 노트북의 현재 위치에 붙임
		}
}

void rotate(int row, int col) // 90도 회전시키는 함수
{
	int tmp[10][10];
	for(int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			tmp[i][j] = sticker[i][j]; // 임시 배열에 복사
	memset(sticker, 0, sizeof(sticker)); // 스티커 초기화
	// 행과 열을 뒤집는다.
	for(int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			sticker[i][j] = tmp[row - 1 - j][i]; // 90도 회전
		}

}

bool attempt(int row, int col, int cnt)
{
	if (cnt == 4) return false; // 모든 방향 확인 후 붙일 수 없다면 false리턴

	bool possible = false; // 붙일 수 있는지 확인
	if (n >= row && m >= col) // 노트북 범위에 맞을때만 확인
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				possible = true;
				if (i + row <= n && j + col <= m) // 범위 내에서
				{
					for (int x = 0; x < row; x++)
					{
						for (int y = 0; y < col; y++)
						{
							if (sticker[x][y] == 1 && a[i + x][j + y] == 1) // 스티커가 붙은 곳에 스티커를 붙이는 경우 불가능
							{ // 붙일 수 없는 경우
								possible = false;
								break;
							}
						}
						if (!possible) break;
					}
				}
				else possible = false; // 범위를 벗어나면 불가능

				if (possible) // 붙일 수 있는 경우
				{
					attach(i, j, row, col); // 노트북에 붙이고 true리턴
					return true;
				}
			}
	}

	if (!possible) // 현재 모양으로 붙일 수 없는 경우
	{
		rotate(row, col); // 90도 회전
		if (attempt(col, row, cnt + 1)) return true; // 회전하면 row, col이 바뀌므로 바꿔서 재귀
		else return false;
	}

}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;

	while (k--)
	{
		int row, col;
		cin >> row >> col;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> sticker[i][j];

		attempt(row, col, 0);
	}
	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 1) ans++; // 스티커 붙은 칸 카운트

	cout << ans << '\n';

}