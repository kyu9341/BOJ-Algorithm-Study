#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<deque>
#include<cstdio>

using namespace std;
const int MAX = 100;
int a[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main(void)
{
	int m, n; // m : ����, n : ����
	cin >> m >> n;
	cin.ignore();

	memset(dist, -1, sizeof(dist)); // -1�� �ʱ�ȭ

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			a[i][j] = str[j] - '0';
	}

	deque<pair<int, int>> dq; // �� ���
	dq.push_back(make_pair(0, 0)); // �ʱ� ��ġ
	dist[0][0] = 0;

	while (!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) // ���� ������
			{
				if (dist[nx][ny] == -1 && a[nx][ny] == 0) // �湮���� ���� �̷��̰�(-1) �� ���� ���(0)
				{
					dq.push_front(make_pair(nx, ny)); // ���� �� �տ� push (�� ���� �켱����)
					dist[nx][ny] = dist[x][y]; // �μ� ���� ������ ����
				}
				if (dist[nx][ny] == -1 && a[nx][ny] == 1) // �湮���� ���� �̷��̰�(-1) ���� ���(1)
				{
					dq.push_back(make_pair(nx, ny)); // ���� �� �ڿ� push
					dist[nx][ny] = dist[x][y] + 1; // �μ� ���� ���� + 1
				}
			}
		}
	}
	cout << dist[n - 1][m - 1] << '\n';

}