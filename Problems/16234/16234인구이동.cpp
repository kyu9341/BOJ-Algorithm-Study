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
int cnt[MAX + 1]; // �� �׷쿡 ���ϴ� ������ �� 
int sum[MAX + 1]; // �� �׷��� ���ϴ� ������ �α����� �� 
int n, l, r;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0 , 0 };
vector<pair<int, int>> v[MAX + 1];
void dfs(int x, int y, int num) // dfs�� ���� ������ �׷��ȣ�� �ű��.
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
			if (gap >= l && gap <= r) //  ������ �α� ���̰� L�� �̻�, R�� ���϶��
			{
				dfs(nx, ny, num); // ���� �׷����� ���´�.
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
		memset(group, 0, sizeof(group)); // �׷� ��ȣ �ʱ�ȭ
		int num = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (group[i][j] == 0) // �׷쿡 ������ �ʴ� ������ ���
				{
					dfs(i, j, ++num);
				}
			}
		
		memset(cnt, 0, sizeof(cnt)); // �� �׷쿡 ���ϴ� ������ �� �ʱ�ȭ
		memset(sum, 0, sizeof(sum)); // �� �׷��� ���ϴ� ������ �α����� �� �ʱ�ȭ
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cnt[group[i][j]]++;
				sum[group[i][j]] += a[i][j];
				v[group[i][j]].push_back(make_pair(i, j)); // ���� �׷쿡 �ش��ϴ� ������ ��ǥ�� ����
			}
		
		bool check = true; // ���漱�� �����ϴ� ���� �ִ��� �Ǻ�
		for (int k = 1; k <= MAX; k++) // ���� 1���� 10000����
		{
			if (cnt[k] >= 2) // �׷쿡 ���� ������ ���� 2�̻��̸� ������ ������ ��.
			{
				for (int i = 0; i < v[k].size(); i++)
				{
					int x = v[k][i].first;
					int y = v[k][i].second;

					a[x][y] = sum[k] / cnt[k]; // �α� �̵� ���

				}
				check = false;
			}
			v[k].clear(); // ���� �ʱ�ȭ
		}

		if (check) break; // ������ �����ϴ� ���� ���ٸ� ����
		ans++; // �α� �̵� Ƚ�� ī��Ʈ
	
	}

	cout << ans << '\n';

}