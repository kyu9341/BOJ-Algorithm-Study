#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;

int d[25][25];
int a[25][25];
int dx[] = { 0, 0, 1, -1 }; // �����¿� �̵� ��ǥ
int dy[] = { 1, -1, 0, 0 };
int n; // ������ ũ��

void dfs(int x, int y, int count)
{
	d[x][y] = count; // ���� ��ǥ�� ���� ��ȣ�� ����

	for (int i = 0; i < 4; i++) // �����¿� Ž��
	{
		int nx = x + dx[i];
		int ny = y + dy[i]; 

		if (nx >= 0 && ny >= 0 && nx < n && ny < n) // ������ ���� ������
		{
			if (a[nx][ny] == 1 && d[nx][ny] == 0) // ������ ��ǥ�� ���� �ְ�, ���� Ž������ ���� ���(���� ��ȣ�� �Ⱥپ��ִ� ���)
			{
				dfs(nx, ny, count);
			}
		}
	}

}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%1d", &a[i][j]);


	int count = 0; // ���� ��ȣ(���� ����� ����)
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1 && d[i][j] == 0) // ���� ��ǥ�� ���� �ְ� Ž������ ���� ���
			{
				dfs(i, j, count + 1);
				count++;
			}
				
		}

	int ans[25 * 25] = { 0 };

	cout << count << '\n';

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ans[d[i][j]]++; // ������ȣ �� ������ ���� �ľ�
		}

	sort(ans + 1, ans + count + 1); // ���� ��ȣ�� 1���� �ٿ����Ƿ�


	for (int i = 1; i <= count; i++)
		cout << ans[i] << '\n';

}