#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
const int MAX = 100;
int n, l;
int a[MAX][MAX];
bool check_row[MAX];
bool check_col[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
	{
		int cnt = 1; // 평지의 수
		check_row[i] = true; // 초기값 true (지나갈 수 있는 상태)
		bool check_d = false; // 내려가는 경사로를 거친 상태라면 true

		for (int j = 0; j < n - 1; j++)
		{
			int gap = a[i][j + 1] - a[i][j];
			if (gap > 1 || gap < -1) // 높이차가 2 이상이면 불가능한 경우
			{
				check_row[i] = false;
				break;
			}
			if (gap == 0) // 같은 높이인 경우
			{
				cnt++; // 같은 높이의 개수
				if (l != 1 && check_d && cnt >= l) // 내려가는 경사로를 놓을 수 있는 경우
				{  // 경사로의 길이가 1인 경우는 예외
					check_d = false; // 평지로 인식
					cnt = 0;
				}
			}
			else if (gap == 1) // 높이가 높아진 경우
			{
				if (l != 1 && check_d) // 경사로가 내려가다가 바로 올라가는 경우 불가능
				{
					check_row[i] = false;
					break;
				}
				if (l == 1 && check_d && cnt == 1)
				{  // 경사로의 길이가 1일 때, 내려가다가 바로 올라오는 경우 불가능
					check_row[i] = false;
					break;
				} // l = 1일 때, 내려가는 경사로를 놓고 다시 올라가는 경사로를 놓을 수 있는 경우
				else if(l == 1 && check_d && cnt > 1) check_d = false;

				if (cnt < l) // 올라가는 경사로를 놓을 수 없는 경우 불가능
				{
					check_row[i] = false;
					break;
				}
				cnt = 1; // 높이가 바뀌었으므로 초기화
			}
			else if (gap == -1) // 높이가 낮아졌다면
			{
				if (l != 1 && check_d) // 연속으로 내려가는 경사로를 두 번 놓을 수 없음
				{ // 1은 예외
					check_row[i] = false;
					break;
				}
				check_d = true; // 다음 높이에서 경사로의 길이를 체크
				cnt = 1;
			}

			if (l != 1 && j == n - 2 && check_d) check_row[i] = false; // 마지막 지점에서 내려갈 때 경사로를 만들지 못하는 경우
		}
	}


	for (int j = 0; j < n; j++)
	{
		int cnt = 1; // 평지의 수 
		check_col[j] = true; // 초기값 true (지나갈 수 있는 상태)
		bool check_d = false; // 내려가는 경사로를 거친 상태라면 true

		for (int i = 0; i < n - 1; i++)
		{
			int gap = a[i + 1][j] - a[i][j];
			if (gap > 1 || gap < -1) // 높이차가 2 이상이면 불가능한 경우
			{
				check_col[j] = false;
				break;
			}
			if (gap == 0) // 같은 높이인 경우
			{
				cnt++; // 같은 높이의 개수
				if (l != 1 && check_d && cnt >= l)  // 내려가는 경사로를 놓을 수 있는 경우
				{ // 경사로의 길이가 1인 경우는 예외
					check_d = false; // 다시 평지로 인식
					cnt = 0;
				}
			}
			else if (gap == 1) // 높이가 높아진 경우
			{
				if (l != 1 && check_d)  // 경사로가 내려가다가 바로 올라가는 경우 불가능
				{
					check_col[j] = false;
					break;
				}
				if (l == 1 && check_d && cnt == 1)
				{ // 경사로의 길이가 1일 때, 내려가다가 바로 올라오는 경우 불가능
					check_col[j] = false;
					break;
				} //l = 1일 때, 내려가는 경사로를 놓고 다시 올라가는 경사로를 놓을 수 있는 경우
				else if (l == 1 && check_d && cnt > 1) check_d = false;

				if (cnt < l) // 올라가는 경사로를 놓을 수 없는 경우 불가능
				{
					check_col[j] = false;
					break;
				}
				cnt = 1; // 높이가 바뀌었으므로 초기화
			}
			else if (gap == -1) // 높이가 낮아졌다면
			{
				if (l != 1 && check_d) // 연속으로 내려가는 경사로를 두 번 놓을 수 없음
				{ // 1은 예외
					check_col[j] = false;
					break;
				}
				check_d = true; // 다음 높이에서 경사로의 길이를 체크
				cnt = 1;
			}

			if (l != 1 && i == n - 2 && check_d) check_col[j] = false; // 마지막 지점에서 내려갈 때 경사로를 만들지 못하는 경우
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) // 각 행, 열 별로 지나갈 수 있는 길의 수 체크
	{
		if (check_row[i])
		{
			ans++;
			//cout << "row : " << i << '\n'; // 디버깅용
		}
		if (check_col[i])
		{
			ans++;
			//cout << "col : " << i << '\n'; // 디버깅용
		}
	}

	cout << ans << '\n';
}