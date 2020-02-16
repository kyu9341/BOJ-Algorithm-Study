#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 }; // x, y�� ����� ��ġ
int dy[] = { 1, 2, 2, 1, -1, -2, -2 ,-1 };
bool check[301][301];
int d[301][301]; // �̵� Ƚ��
int n; // �� ���� ����

bool isInside(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < n)
		return true;
	else
		return false;
}

void bfs(int x, int y)
{
	memset(d, 0, sizeof(d)); // d, check �迭 �ʱ�ȭ
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 0;
	check[x][y] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) // 8���� ��� Ž��
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny)) // ü���� �������� Ȯ��
			{
				if (check[nx][ny] == false)
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = true; // �湮 ó��
					d[nx][ny] = d[x][y] + 1; // �̵� Ƚ�� �߰�
				}
			}
		}
	}
}
int main(void)
{
	int t; // test case
	cin >> t;

	while (t--)
	{
		cin >> n;
		int sx, sy, ex, ey;
		cin >> sx >> sy; // ���� ��ġ
		cin >> ex >> ey; // ������ ��ġ

		bfs(sx, sy);

		cout << d[ex][ey] << '\n';

	}
}