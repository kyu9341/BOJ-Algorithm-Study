#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
int a[101][101];
bool check[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int dist[101][101]; // (0, 0)���������� �Ÿ�
int n, m; // �̷��� ��(����), ��(����)

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	dist[0][0] = 1;

	while (!q.empty())
	{
		x = q.front().first; // ���� ��ǥ
		y = q.front().second;
		q.pop(); // ��ǥ ���� �� pop (bfs)

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i]; // ���� ��ǥ
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) // �̷��� ���� ������
			{
				if (check[nx][ny] == false && a[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny)); // �湮�� �� push
					check[nx][ny] = true; // �湮 ó��
					dist[nx][ny] = dist[x][y] + 1; // (0, 0)�� 1�� �����Ͽ� �Ÿ� ���
				}
			}
		}

	}
}

int main(void)
{
	cin >> n >> m;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < str.length(); j++)
			a[i][j] = int(str[j] - '0'); // ������ ��ȯ
	}
	bfs(0, 0);

	cout << dist[n - 1][m - 1] << '\n';

}