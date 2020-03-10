#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
char a[7000][7000];
int n;

void printStar() // 별표 출력
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
	if (n == 1) // n이 1일때 별표 저장
	{
		a[x][y] = '*';
		return;
	}

	int m = n / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue; // 가운데를 비움
			go(x + i * m, y + j * m, m); // 9분할 재귀
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