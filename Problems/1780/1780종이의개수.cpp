#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
int a[2187][2187];
int cnt[3];

bool same(int x, int y, int n) // ���� ������ ��� ĭ�� ������ Ȯ���ϴ� �Լ�
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (a[x][y] != a[i][j])
			{
				return false;
			}
		}
	return true;
}

void div(int x, int y, int n) // (x, y) : ������ ������(������� ������), n : ������ ũ��
{
	if (same(x, y, n)) // ��� ĭ�� ���� ���
	{
		if (a[x][y] == 0)
			cnt[0]++;
		else if (a[x][y] == 1)
			cnt[1]++;
		else
			cnt[2]++;
		return;
	}
	else // ��� ���� ���� ������ �ٽ� �����Ͽ� Ȯ��
	{
		for (int i = x; i < x + n; i += n / 3) // ��ü�� 9�����Ͽ� ��� Ȯ��
			for (int j = y; j < y + n; j += n / 3)
			{
				div(i, j, n / 3);
			}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	div(0, 0, n);

	cout << cnt[2] << '\n';
	cout << cnt[0] << '\n';
	cout << cnt[1] << '\n';
}
