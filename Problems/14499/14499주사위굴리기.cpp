#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
int a[21][21];
int dice[3][3];
int n, m, k;

bool check(int x, int y) // ���� x,y�� ������ ���ϴ��� Ȯ��
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return true;
	else return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x, y;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	vector<int> cmd(k); // ��ɾ� ����
	for (int i = 0; i < k; i++)
		cin >> cmd[i];

	// �ֻ����� 6��
	int bottom = 0;
	int top = 0;
	int north = 0;
	int south = 0;
	int east = 0;
	int west = 0;

	for (int i = 0; i < k; i++)
	{
		int nx, ny;
		switch (cmd[i])
		{
		case 1: // �������� �̵��ϴ� ���
			nx = x; // ���� ��ǥ
			ny = y + 1;
			if (check(nx, ny))
			{ // �ֻ����� �� �� �̵�
				int temp = bottom;
				bottom = east;
				east = top;
				top = west;
				west = temp;
				if (a[nx][ny] == 0) // ������ ĭ�� 0�� ���
					a[nx][ny] = bottom; // �ֻ����� �ٴڸ��� ����
				else
				{
					bottom = a[nx][ny]; // 0�� �ƴϸ� �ֻ����� �ٴڸ����� ����
					a[nx][ny] = 0; // ������ ĭ�� 0���� ����
				}
			}
			else continue; // ������ ��� ��� �ش� ��� ����
			x = nx;
			y = ny;
			break;
		case 2: // �������� �̵��ϴ� ���
			nx = x;
			ny = y - 1;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = west;
				west = top;
				top = east;
				east = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		case 3: // �������� �̵��ϴ� ���
			nx = x - 1;
			ny = y;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = north;
				north = top;
				top = south;
				south = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		case 4: // �������� �̵��ϴ� ���
			nx = x + 1;
			ny = y;
			if (check(nx, ny))
			{
				int temp = bottom;
				bottom = south;
				south = top;
				top = north;
				north = temp;
				if (a[nx][ny] == 0)
					a[nx][ny] = bottom;
				else
				{
					bottom = a[nx][ny];
					a[nx][ny] = 0;
				}
			}
			else continue;
			x = nx;
			y = ny;
			break;
		}
		cout << top << '\n'; // ���� ���

	}
	
}