#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
int a[2187][2187];
int cnt[3];

bool same(int x, int y, int n) // 현재 종이의 모든 칸이 같은지 확인하는 함수
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (a[x][y] != a[i][j])
			{
				return false;
			}
		}
	return true;
}

void div(int x, int y, int n) // (x, y) : 종이의 시작점(가장왼쪽 가장위), n : 종이의 크기
{
	if (same(x, y, n)) // 모든 칸이 같은 경우
	{
		if (a[x][y] == 0)
			cnt[0]++;
		else if (a[x][y] == 1)
			cnt[1]++;
		else
			cnt[2]++;
		return;
	}
	else // 모든 같이 같지 않으면 다시 분할하여 확인
	{
		for (int i = x; i < x + n; i += n / 3) // 전체를 9분할하여 모두 확인
			for (int j = y; j < y + n; j += n / 3)
			{
				div(i, j, n / 3);
			}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	div(0, 0, n);

	cout << cnt[2] << '\n';
	cout << cnt[0] << '\n';
	cout << cnt[1] << '\n';
}
