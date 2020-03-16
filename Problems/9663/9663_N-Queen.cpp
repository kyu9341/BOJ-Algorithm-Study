#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;
int dx[] = { -1, -1};
int dy[] = { -1, 1 };
vector<pair<int, int>> v;
bool check[15][15];
int n;
int ans = 0;




bool possible(int x, int y)
{
	for (int i = x - 1, j = 1; i >= 0; i--, j++)
	{
		if (check[i][y]) return false; // ���� ���� ���� ���� �ִ��� Ȯ��
		if (y - j >= 0 && check[i][y - j]) return false; // ���� �� �밢�� Ȯ��
		if (y + j < n && check[i][y + j]) return false; // ���� �� �밢�� Ȯ��
	}
	return true;
}

void go(int row)
{
	if (row == n) // ���� �� �ִ� ���
	{
		ans++;
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (possible(row, col)) // ���� (row, col)�� ���� ���� �� �ִ��� Ȯ��
		{
			check[row][col] = true; // ���� ���� ǥ��
			go(row + 1);
			check[row][col] = false;
		}
	}
}

int main(void)
{
	cin >> n;
	go(0);

	cout << ans << '\n';
}
