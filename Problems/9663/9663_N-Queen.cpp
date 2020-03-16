#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;
int dx[] = { -1, -1};
int dy[] = { -1, 1 };
vector<pair<int, int>> v;
bool check[15][15];
int n;
int ans = 0;




bool possible(int x, int y)
{
	for (int i = x - 1, j = 1; i >= 0; i--, j++)
	{
		if (check[i][y]) return false; // 같은 열에 놓인 퀸이 있는지 확인
		if (y - j >= 0 && check[i][y - j]) return false; // 좌측 위 대각선 확인
		if (y + j < n && check[i][y + j]) return false; // 우측 위 대각선 확인
	}
	return true;
}

void go(int row)
{
	if (row == n) // 놓을 수 있는 경우
	{
		ans++;
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (possible(row, col)) // 현재 (row, col)에 퀸을 놓을 수 있는지 확인
		{
			check[row][col] = true; // 놓은 것을 표시
			go(row + 1);
			check[row][col] = false;
		}
	}
}

int main(void)
{
	cin >> n;
	go(0);

	cout << ans << '\n';
}
