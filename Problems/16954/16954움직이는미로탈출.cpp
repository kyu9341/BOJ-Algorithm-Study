#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
int a[8][8];
bool check[8][8];
int dx[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, 1, -1, -1 };

void printA() // ���� �̵� Ȯ��
{
	cout << '\n';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void move() // ���� �̵���Ű�� �Լ�
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			if (i == 0)
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = a[i - 1][j];
			}
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			char input;
			cin >> input;
			if (input == '.') a[i][j] = 0; // . : 0, # : 1�� ��ȯ
			else a[i][j] = 1;
		}
	pair<int, int> start = make_pair(7, 0); // ���� ����
	pair<int, int> end = make_pair(0, 7); // ��ǥ ����

	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	q.push(start); // ���� �Ʒ� ĭ

	while (!q.empty() || !nq.empty()) // �� ť�� ��� ����� ������
	{
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (a[x][y] == 1) continue; // ĳ������ ��ġ�� ���� �� ���

			if (x == end.first && y == end.second) // ��ǥ ������ ������ ���
			{
				cout << 1 << '\n';
				return 0;
			}

			nq.push(make_pair(x, y)); // ���ڸ��� ��ġ�ϴ� ���

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) // ���� ������
				{
					if (a[nx][ny] == 0) // ���� ��ǥ�� �� ĭ�� ���
					{
						nq.push(make_pair(nx, ny)); // 8���� �߰�
					}
				}
			}

		} // 1�ʰ� ��� ���� ��
		move(); // �� �̵�

		while (!nq.empty())
		{
			int x = nq.front().first;
			int y = nq.front().second;
			nq.pop();
			 
			if (a[x][y] == 1) continue;  // ĳ������ ��ġ�� ���� �� ���

			if (x == end.first && y == end.second) // ��ǥ ������ ������ ���
			{
				cout << 1 << '\n';
				return 0;
			}

			q.push(make_pair(x, y));

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8)
				{
					if (a[nx][ny] == 0) // ���� ��ǥ�� �� ĭ�� ���
					{
						q.push(make_pair(nx, ny)); // 8���� �߰�
					}
				}
			}

		} // 1�ʰ� ���� ��
		move(); // �� �̵�

	}

	cout << 0 << '\n';
}