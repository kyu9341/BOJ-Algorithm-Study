#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
const int MAX = 40;
int n, m, k;
int a[40][40];
int sticker[10][10];

void attach(int i, int j, int row, int col) // ��ƼĿ�� ��Ʈ�Ͽ� ���̴� �Լ�
{
	for (int x = i; x < i + row; x++)
		for (int y = j; y < j + col; y++)
		{
			if(a[x][y] == 0)
				a[x][y] = sticker[x - i][y - j]; // ��Ʈ���� ���� ��ġ�� ����
		}
}

void rotate(int row, int col) // 90�� ȸ����Ű�� �Լ�
{
	int tmp[10][10];
	for(int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			tmp[i][j] = sticker[i][j]; // �ӽ� �迭�� ����
	memset(sticker, 0, sizeof(sticker)); // ��ƼĿ �ʱ�ȭ
	// ��� ���� �����´�.
	for(int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			sticker[i][j] = tmp[row - 1 - j][i]; // 90�� ȸ��
		}

}

bool attempt(int row, int col, int cnt)
{
	if (cnt == 4) return false; // ��� ���� Ȯ�� �� ���� �� ���ٸ� false����

	bool possible = false; // ���� �� �ִ��� Ȯ��
	if (n >= row && m >= col) // ��Ʈ�� ������ �������� Ȯ��
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				possible = true;
				if (i + row <= n && j + col <= m) // ���� ������
				{
					for (int x = 0; x < row; x++)
					{
						for (int y = 0; y < col; y++)
						{
							if (sticker[x][y] == 1 && a[i + x][j + y] == 1) // ��ƼĿ�� ���� ���� ��ƼĿ�� ���̴� ��� �Ұ���
							{ // ���� �� ���� ���
								possible = false;
								break;
							}
						}
						if (!possible) break;
					}
				}
				else possible = false; // ������ ����� �Ұ���

				if (possible) // ���� �� �ִ� ���
				{
					attach(i, j, row, col); // ��Ʈ�Ͽ� ���̰� true����
					return true;
				}
			}
	}

	if (!possible) // ���� ������� ���� �� ���� ���
	{
		rotate(row, col); // 90�� ȸ��
		if (attempt(col, row, cnt + 1)) return true; // ȸ���ϸ� row, col�� �ٲ�Ƿ� �ٲ㼭 ���
		else return false;
	}

}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;

	while (k--)
	{
		int row, col;
		cin >> row >> col;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> sticker[i][j];

		attempt(row, col, 0);
	}
	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 1) ans++; // ��ƼĿ ���� ĭ ī��Ʈ

	cout << ans << '\n';

}