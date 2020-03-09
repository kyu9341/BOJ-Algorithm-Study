#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;
int a[10][10];
bool check[10][10];
int tmp[10][10];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> d;
vector<pair<int, int>> wall;
int ans = 0;

int n, m;

int bfs() //  ���� ���� ������ ���� ���� ũ�� ����
{
	memset(check, false, sizeof(check)); // check �迭 �ʱ�ȭ

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[i][j] = a[i][j]; // tmp�� a����

	for (int i = 0; i < 3; i++)
		tmp[wall[i].first][wall[i].second] = 1; // ���� ���� ���� ��ǥ �߰�

	queue<pair<int, int>> q;
	for (int i = 0; i < d.size(); i++)
	{
		q.push(d[i]);
		check[d[i].first][d[i].second] = true; // ���̷��� ���� �������� bfs ����
	}

	while (!q.empty()) // bfs
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < n && ny < m && nx >= 0 && ny >= 0) // ���� ������
			{
				if (!check[nx][ny] && tmp[nx][ny] == 0) // �湮���� �ʾҰ�, ���� ������ ���
				{
					q.push(make_pair(nx, ny)); 
					check[nx][ny] = true;
					tmp[nx][ny] = 2; // ������Ų��.
				}
			}
		}
	}
		
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == 0)
				res++; // ���� ���� ���� count
		}
	return res;
}

void go(int index, int start)
{
	if (index == 3)
	{
		int save = bfs();
		if (ans < save)
			ans = save; // ���������� �ִ� ����
		return;
	}
	
	for (int i = start; i < n * m; i++) // ���� ���ϱ�
	{ // �ߺ� ����
		if (a[i / m][i % m] == 0) 
		{
			wall.push_back(make_pair(i / m, i % m));
			go(index + 1, i + 1); // ������� ���� ����, ���� ������
			wall.pop_back();
		}
	}
}

int main(void)
{
	cin >> n >> m;

	for(int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2) d.push_back(make_pair(i, j)); // ���̷��� ���� ���� ����
		}

	go(0, 0);

	cout << ans << '\n';
	
}