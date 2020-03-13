#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<climits>

using namespace std;
const int MAX = 100;
int a[MAX + 1][MAX + 1];
bool check[MAX + 1][MAX + 1];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int n;


bool bfs(int min, int max) // ���� �ִ�, �ּڰ����� (n-1,n-1)���� �̵� �������� Ȯ���ϴ� �Լ�
{
	if (a[0][0] < min || a[0][0] > max) return false; // ������ ����� false
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	check[0][0] = true;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n)
			{
				if (!check[nx][ny])
				{
					if (a[nx][ny] <= max && a[nx][ny] >= min) // �ִ� �ּ��� ���� ������ �̵�
					{
						q.push(make_pair(nx, ny));
						check[nx][ny] = true;
					}
				}
			}
		}
	}
	return check[n - 1][n - 1]; // (n-1,n-1)���� �̵� �������� �Ǻ�
}

bool go(int mid)
{
	for (int i = 0; i + mid <= 200; i++) // 0���� ������ ���� 200���� ���� ������
	{ // ���̰� mid�� ��� �ִ�, �ּ��� ��츦 Ȯ��
		if (bfs(i, i + mid))
			return true;
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	int max = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (max < a[i][j]) max = a[i][j];
		}
	int right = max;
	int left = 0;
	int ans = max;

	while (left <= right) // �̺� Ž��
	{
		int mid = (left + right) / 2;
		memset(check, false, sizeof(check));
		if (go(mid))
		{
			if (ans > mid)
				ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans << '\n';

}