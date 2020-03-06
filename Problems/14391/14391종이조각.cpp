#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
int n, m; // 가로, 세로
int a[4][4];
bool check[4][4]; 
int xy[4][4]; // 0 : 가로로 합, 1 : 세로로 합
vector<int> ans;

int dfs(int x, int y, int sum) // 현재 위치부터 연결된 가로 또는 세로의 합을 리턴
{
	check[x][y] = true;
	if (xy[x][y] == 0) // 가로로 확인하는 경우
	{
		if (y + 1 < m && xy[x][y] == xy[x][y + 1] && !check[x][y + 1])
			sum = dfs(x, y + 1, (sum * 10) + a[x][y]); // 가로로 종이를 이어붙여 넘김
		else
			return sum * 10 + a[x][y]; // 마지막 수 처리
	}
	if (xy[x][y] == 1) // 세로로 확인하는 경우
	{
		if (x + 1 < n && xy[x][y] == xy[x + 1][y]  && !check[x + 1][y])
			sum = dfs(x + 1, y, (sum * 10) + a[x][y]); // 세로로 종이를 이어붙여 넘김
		else
			return sum * 10 + a[x][y]; // 마지막 수 처리
	}
	return sum;
}

int makeSum()
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (!check[i][j])
			{
				sum += dfs(i, j, 0);
			}
		}
	return sum;
}

void go(int index)
{
	if (index == m * n)
	{		
		memset(check, false, sizeof(check));
		ans.push_back(makeSum()); // 정답 후보
		return;
	}
	// 0 ~ 15로 인덱스를 돌며 모든 경우 확인
	xy[index / m][index % m] = 1; // 1을 넣는 경우
	go(index + 1);
	xy[index / m][index % m] = 0; // 0을 넣는 경우
	go(index + 1);

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			a[i][j] = str[j] - '0';
	}

	go(0);

	auto max = max_element(ans.begin(), ans.end());
	cout << *max << '\n'; // 최댓값 출력
		

}