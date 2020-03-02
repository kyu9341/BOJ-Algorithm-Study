#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int dx[] = { -2, -2, 0, 0, 2, 2 }; // (x, y)�� �̵� ������ ��� ��ǥ
int dy[] = { -1, 1, -2, 2, -1, 1 };
bool check[201][201];
int dist[201][201];

int main(void)
{
	int n;
	cin >> n;

	int sr, sc, er, ec; // ������, ������
	cin >> sr >> sc >> er >> ec;

	memset(dist, -1, sizeof(dist)); // �Ÿ��� ��� -1�� �ʱ�ȭ

	queue<pair<int, int>> q;
	q.push(make_pair(sr, sc)); // ���� ��ǥ push
	check[sr][sc] = true;
	dist[sr][sc] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) // �̵� ������ ��� ��� Ȯ��
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) // ���� ������
			{
				if (check[nx][ny] == false) // ���� Ȯ������ ���� ���
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1; // ���� ��ǥ push �� �Ÿ� �߰�
				}
			}
		}

	}

	cout << dist[er][ec] << '\n';
}