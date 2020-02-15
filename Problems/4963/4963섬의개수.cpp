#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int a[50][50];
bool check[50][50];
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 }; // �����¿� �밢��
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int w, h; // �ʺ�, ����


void dfs(int x, int y)
{
	check[x][y] = true; // �湮 ó��
	
	for (int i = 0; i < 8; i++) // �����¿�, �밢�� Ž�� (8��)
	{
		int nx = x + dx[i]; // ���� x��ǥ
		int ny = y + dy[i]; // ���� y��ǥ

		if (nx >= 0 && ny >= 0 && nx < h && ny < w) // ������ ���� ����
		{
			if (a[nx][ny] == 1 && check[nx][ny] == false) // ���� ��ǥ�� �����̰� �湮���� �ʾҴٸ�
			{
				dfs(nx, ny);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> a[i][j];

		memset(check, false, sizeof(check)); // check �ʱ�ȭ

		int count = 0; // �������� ����
		for(int x = 0; x < h; x++)
			for (int y = 0; y < w; y++)
			{
				if (a[x][y] == 1 && check[x][y] == false) // ���� ��ǥ�� �����̰� �湮���� ���� ���
				{
					count++; // ���� ��� ī��Ʈ
					dfs(x, y);
				}
			}
		cout << count << '\n';
	}
}