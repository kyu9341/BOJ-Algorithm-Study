#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;
int a[51][51];
int dx[] = { -1, 0, 1, 0 }; // 0  : ��, 1 : ��, 2 : ��, 3 : ��
int dy[] = { 0, 1, 0,  -1 };
int n, m;
int ans = 0; // û�ұⰡ �ִ� ĭ�� �׻� ��ĭ

int calc_dir(int dir, int rotation) // û�ұ��� ȸ��
{
	int res = dir + rotation;
	if (res > 3) res -= 4;
	if(res < 0) res += 4;
	return res;
}
void go(int x, int y, int dir)
{
	if (a[x][y] == 0) // û������ �ʾҴٸ� 
	{
		a[x][y] = 2; // û��
		ans++; // ī��Ʈ
	}

	int cnt = 4;
	while (cnt--) // 4���� Ȯ��
	{
		dir = calc_dir(dir, -1); // �������� ȸ��
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (a[nx][ny] == 0) // ��ĭ�̶�� û��
			{
				go(nx, ny, dir);
				return; // ���� ĭ���� �Ѿ ���� ������ ������ �˻� x
			}
		}
	}// �˻� ��

	// �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
	int rear = calc_dir(dir, -2); // ���� ���� ����
	int nx = x + dx[rear];
	int ny = y + dy[rear];
	if (nx >= 0 && ny >= 0 && nx < n && ny < m)
	{
		if (a[nx][ny] == 1) // ������ ���Ѵٸ�
		{
			cout << ans << '\n';
			exit(0);
		}
		else // �����Ѵ�
		{
			go(nx, ny, dir); // ������ ����
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	int sx, sy, dir;
	cin >> sx >> sy >> dir;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	go(sx, sy, dir);

}