#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<tuple>

using namespace std;
int a[21][21];
int d[21][21];
int dx[] = { 0, -1, 1, 0 }; 
int dy[] = { 1, 0, 0, -1 };
int n;

tuple<int, int, int> bfs(int x, int y, int size)
{

	memset(d, -1, sizeof(d));
	vector<tuple<int, int, int>> ans;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 0;

	while (!q.empty())
	{
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && d[nx][ny] == -1)
			{
				bool ok = false;
				bool eat = false;
				if (a[nx][ny] == 0 || a[nx][ny] == size) ok = true; // 이동 가능 여부
				if (a[nx][ny] != 0 && a[nx][ny] < size)  // 먹을 수 있는지 확인
				{
					ok = true; // 이동 가능하고
					eat = true; // 먹을 수 있다
				}
				if (ok) // 이동이 가능한 상태라면
				{
					q.push(make_pair(nx, ny)); // 다음 위치
					d[nx][ny] = d[x][y] + 1; // 거리 1증가
					if (eat) // 먹을 수 있는 물고기를 만난 경우
						ans.push_back(make_tuple(d[nx][ny], nx, ny)); // 먹을 수 있는 물고기가 여러마리라면 위, 왼쪽이 우선
				}
			}
			
		}
	}
	if (ans.empty()) // 먹을 수 있는 물고기가 없는 경우
		ans.push_back(make_tuple(-1, -1, -1)); // -1리턴

	sort(ans.begin(), ans.end()); // 가장 가까운 물고기부터
	// 거리가 같다면 가장 위, 다음 가장 왼쪽 (거리, 행, 열)순서로 오름차순 정렬
	return ans[0];
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int x, y;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 9) // 상어의 위치
			{
				x = i;
				y = j;
				a[i][j] = 0; // 0으로 초기화
			}
		}

	int ans = 0;
	int size = 2; // 크기
	int exp = 0; // 경험치

	while (true)
	{
		int dist;
		tie(dist, x, y) = bfs(x, y, size); // 상어의 위치 갱신(가장 가까운 물고기의 위치)
		if (dist == -1) break; // 더 이상 먹을 수 있는 물고기가 없다면
		a[x][y] = 0; // 물고기를 먹은 자리는 0으로 초기화
		ans += dist; // 이동 거리 추가(초)
		exp++; // 물고기 경험치
		if (size == exp)
		{
			size++;
			exp = 0;
		}
	}

	cout << ans << '\n';
}