#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
int a[9][9];
bool check_row[10][10];
bool check_col[10][10];
bool check_square[10][10];

int square(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}

void go(int index)
{
	if (index == 81) // ���� �������� ��� �� ���α׷� ����
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
		exit(0); 
	}

	int x = index / 9; // 0 ~ 80 �� ��, ���� ��ȯ
	int y = index % 9;
	if (a[x][y] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (!check_row[x][i] && !check_col[i][y] && !check_square[square(x, y)][i]) // ���� ��, ��, �簢���� ���� ���� Ȯ��
			{
				check_row[x][i] = check_col[i][y] = check_square[square(x, y)][i] = true; // ���� �־����Ƿ� üũ
				a[x][y] = i;
				go(index + 1); // ���� �ְ� �Ѿ
				a[x][y] = 0; // Ȯ�� �� �ʱ�ȭ
				check_row[x][i] = check_col[i][y] = check_square[square(x, y)][i] = false;
			}
		}
	}
	else
		go(index + 1); // 0�� �ƴ϶�� ��� ����

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> a[i][j];
			if (a[i][j] != 0)
			{
				check_row[i][a[i][j]] = true; // i��° �࿡ �����ϴ� �� üũ
				check_col[a[i][j]][j] = true; // j��° ���� �����ϴ� �� üũ
				check_square[square(i, j)][a[i][j]] = true; // n��° �簢���� �����ϴ� �� üũ
			}
		}

	go(0);
	
}