#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

using namespace std;
int a[50][50];
int b[50][50];

void reverse33(int x, int y) // 3x3�� ������ �Լ� 0 -> 1, 1 -> 0
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			a[i][j] = 1 - a[i][j]; // a[i][j]�� 0�̸� 1��, 1�̸� 0���� �ٲ�
		}
	}
}

int main(void)
{
	int n, m; // ����� ũ��
	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++) // a, b ��� �Է�
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
			a[i][j] = str[j] - '0';
	}
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
			b[i][j] = str[j] - '0';
	}

	int ans = 0;
	for (int i = 0; i < n - 2; i++) // 3x3 ��ľ� �����ϹǷ� n - 2����
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] != b[i][j]) // ���� �ε����� ���Ұ� ���� �ٸ��ٸ� ���� ����
			{
				reverse33(i, j);
				ans++;
			}
		}
	}

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != b[i][j]) // ����� ���Ͽ� �ٸ��ٸ� -1
			{
				ans = -1;
			}
		}
	cout << ans << '\n';
}