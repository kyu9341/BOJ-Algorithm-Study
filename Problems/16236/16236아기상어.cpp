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
				if (a[nx][ny] == 0 || a[nx][ny] == size) ok = true; // �̵� ���� ����
				if (a[nx][ny] != 0 && a[nx][ny] < size)  // ���� �� �ִ��� Ȯ��
				{
					ok = true; // �̵� �����ϰ�
					eat = true; // ���� �� �ִ�
				}
				if (ok) // �̵��� ������ ���¶��
				{
					q.push(make_pair(nx, ny)); // ���� ��ġ
					d[nx][ny] = d[x][y] + 1; // �Ÿ� 1����
					if (eat) // ���� �� �ִ� ����⸦ ���� ���
						ans.push_back(make_tuple(d[nx][ny], nx, ny)); // ���� �� �ִ� ����Ⱑ ����������� ��, ������ �켱
				}
			}
			
		}
	}
	if (ans.empty()) // ���� �� �ִ� ����Ⱑ ���� ���
		ans.push_back(make_tuple(-1, -1, -1)); // -1����

	sort(ans.begin(), ans.end()); // ���� ����� ��������
	// �Ÿ��� ���ٸ� ���� ��, ���� ���� ���� (�Ÿ�, ��, ��)������ �������� ����
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
			if (a[i][j] == 9) // ����� ��ġ
			{
				x = i;
				y = j;
				a[i][j] = 0; // 0���� �ʱ�ȭ
			}
		}

	int ans = 0;
	int size = 2; // ũ��
	int exp = 0; // ����ġ

	while (true)
	{
		int dist;
		tie(dist, x, y) = bfs(x, y, size); // ����� ��ġ ����(���� ����� ������� ��ġ)
		if (dist == -1) break; // �� �̻� ���� �� �ִ� ����Ⱑ ���ٸ�
		a[x][y] = 0; // ����⸦ ���� �ڸ��� 0���� �ʱ�ȭ
		ans += dist; // �̵� �Ÿ� �߰�(��)
		exp++; // ����� ����ġ
		if (size == exp)
		{
			size++;
			exp = 0;
		}
	}

	cout << ans << '\n';
}