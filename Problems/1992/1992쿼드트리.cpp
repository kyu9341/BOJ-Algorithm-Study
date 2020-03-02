#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;
int a[100][100];
string ans = "";

bool check(int x, int y, int n) // 크기가 n * n인 영상을 확인하는 함수
{
	for(int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (a[x][y] != a[i][j])
				return false;
		}
	return true;
}

void go(int x, int y, int n)
{
	if (check(x, y, n)) // 현재 크기의 영상 확인
	{
		ans += a[x][y]; // 모두 0또는 1로만 이루어져있다면 결과 문자열에 누적
		return;
	}
	else
	{
		ans += '('; // 단계에서 괄호 시작
		int m = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				go(x + m * i, y + m * j, m); // 4분할 하여 재귀
			}
		ans += ')';
	}
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			a[i][j] = str[j];
	}

	go(0, 0, n);
	cout << ans << '\n';
}