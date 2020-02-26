#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

using namespace std;
int a[50][50];
int b[50][50];

void reverse33(int x, int y) // 3x3을 뒤집는 함수 0 -> 1, 1 -> 0
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			a[i][j] = 1 - a[i][j]; // a[i][j]가 0이면 1로, 1이면 0으로 바꿈
		}
	}
}

int main(void)
{
	int n, m; // 행렬의 크기
	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++) // a, b 행렬 입력
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
	for (int i = 0; i < n - 2; i++) // 3x3 행렬씩 연산하므로 n - 2까지
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] != b[i][j]) // 현재 인덱스의 원소가 서로 다르다면 연산 수행
			{
				reverse33(i, j);
				ans++;
			}
		}
	}

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != b[i][j]) // 행렬을 비교하여 다르다면 -1
			{
				ans = -1;
			}
		}
	cout << ans << '\n';
}