#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int a[1001][1001];
int d[1001][1001]; // ���� �丶�信���� �Ÿ�(��¥)
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


int main(void)
{
	int n, m;
	cin >> m >> n;

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			d[i][j] = -1; // �丶�䰡 ���� ���ϴ� ��Ȳ�� ã�� ���� -1�� �ʱ�ȭ(0�� ���� �丶���� �ʱ� ��ġ)
			if (a[i][j] == 1)
			{
				q.push(make_pair(i, j)); // ���� �丶�並 ť�� �־� bfs�� ���������� ���Ѵ�.
				d[i][j] = 0; // ���� �丶�� �ʱ� ��ġ
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

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) // ���� ����
			{
				if (a[nx][ny] == 0 && d[nx][ny] == -1) // ������ �丶���̰� �湮���� ���� ���
				{
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1; // �丶���� �ʱ� ��ġ�� 0, ���� ��ġ�� +1
				}

			}
		}
	}
	int ans = 0; // ��� �ʹ� �ϼ�
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (ans < d[i][j]) // �ִ��� ����(��� �ʹ� ��¥)
				ans = d[i][j]; 
		}
	
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && d[i][j] == -1) // ��� �丶�䰡 ���� �� ���� ���
				ans = -1;
		}

	cout << ans << '\n';
}