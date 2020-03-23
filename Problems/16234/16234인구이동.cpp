#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
const int MAX = 10000;
int a[51][51];
int group[51][51];
int cnt[MAX + 1]; // 각 그룹에 속하는 나라의 수 
int sum[MAX + 1]; // 각 그룹의 속하는 나라의 인구수의 합 
int n, l, r;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0 , 0 };
vector<pair<int, int>> v[MAX + 1];
void dfs(int x, int y, int num) // dfs를 통해 연합의 그룹번호를 매긴다.
{
	if (group[x][y] != 0) return;
	group[x][y] = num;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			int gap = a[x][y] - a[nx][ny];
			if (gap < 0) gap = -gap;
			if (gap >= l && gap <= r) //  나라의 인구 차이가 L명 이상, R명 이하라면
			{
				dfs(nx, ny, num); // 같은 그룹으로 묶는다.
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int ans = 0;
	while (true)
	{
		memset(group, 0, sizeof(group)); // 그룹 번호 초기화
		int num = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (group[i][j] == 0) // 그룹에 속하지 않는 나라인 경우
				{
					dfs(i, j, ++num);
				}
			}
		
		memset(cnt, 0, sizeof(cnt)); // 각 그룹에 속하는 나라의 수 초기화
		memset(sum, 0, sizeof(sum)); // 각 그룹의 속하는 나라의 인구수의 합 초기화
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cnt[group[i][j]]++;
				sum[group[i][j]] += a[i][j];
				v[group[i][j]].push_back(make_pair(i, j)); // 같은 그룹에 해당하는 나라의 좌표를 저장
			}
		
		bool check = true; // 국경선을 공유하는 나라가 있는지 판별
		for (int k = 1; k <= MAX; k++) // 경우는 1부터 10000까지
		{
			if (cnt[k] >= 2) // 그룹에 속한 나라의 수가 2이상이면 국경을 공유한 것.
			{
				for (int i = 0; i < v[k].size(); i++)
				{
					int x = v[k][i].first;
					int y = v[k][i].second;

					a[x][y] = sum[k] / cnt[k]; // 인구 이동 계산

				}
				check = false;
			}
			v[k].clear(); // 벡터 초기화
		}

		if (check) break; // 국경을 공유하는 나라가 없다면 종료
		ans++; // 인구 이동 횟수 카운트
	
	}

	cout << ans << '\n';

}