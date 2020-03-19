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
	if (index == 81) // 답을 구했으면 출력 후 프로그램 종료
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
		exit(0); 
	}

	int x = index / 9; // 0 ~ 80 을 행, 열로 변환
	int y = index % 9;
	if (a[x][y] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (!check_row[x][i] && !check_col[i][y] && !check_square[square(x, y)][i]) // 같은 행, 열, 사각형에 없는 수만 확인
			{
				check_row[x][i] = check_col[i][y] = check_square[square(x, y)][i] = true; // 수를 넣었으므로 체크
				a[x][y] = i;
				go(index + 1); // 수를 넣고 넘어감
				a[x][y] = 0; // 확인 후 초기화
				check_row[x][i] = check_col[i][y] = check_square[square(x, y)][i] = false;
			}
		}
	}
	else
		go(index + 1); // 0이 아니라면 계속 진행

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
				check_row[i][a[i][j]] = true; // i번째 행에 존재하는 수 체크
				check_col[a[i][j]][j] = true; // j번째 열에 존재하는 수 체크
				check_square[square(i, j)][a[i][j]] = true; // n번째 사각형에 존재하는 수 체크
			}
		}

	go(0);
	
}