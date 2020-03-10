#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
char a[7000][7000];
int n;

void printStar() // ��ǥ ���
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j];
		cout << '\n';
	}
}

void go(int x, int y, int n)
{
	if (n == 1) // n�� 1�϶� ��ǥ ����
	{
		a[x][y] = '*';
		return;
	}

	int m = n / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue; // ����� ���
			go(x + i * m, y + j * m, m); // 9���� ���
		}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	memset(a, ' ', sizeof(a));
	go(0, 0, n);
	printStar();
}