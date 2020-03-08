#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
const int mod = 10000;
const int MAX = 10000;
bool check[MAX + 1];

int left(int n) // �������� ȸ��
{
	int f = n / 1000;
	int r = n % 1000;

	int res = r * 10 + f; // �� ���ڸ��� �� �ڷ�

	return res;
}
int right(int n) // ���������� ȸ��
{
	int f = n / 10; 
	int r = n % 10; 

	int res = r * 1000 + f; // ���� �ڷ� �������� ������ 

	return res;
}

void bfs(int n, int goal)
{
	memset(check, false, sizeof(check));
	queue<pair<int, string>> q;
	check[n] = true;
	q.push(make_pair(n, ""));

	while (!q.empty())
	{
		int node = q.front().first;
		string res = q.front().second;
		q.pop();

		if (node == goal) // ��ǥ�� ã�� ���
		{
			cout << res << '\n';
			break;
		}

		int next = 2 * node < MAX ? 2 * node : (2 * node) % mod; // 1�� ����(D)
		if (!check[next])
		{
			q.push(make_pair(next, res + "D"));
			check[next] = true;
		}

		next = node - 1 < 0 ? 9999 : node - 1; // 2�� ����(S)
		if (!check[next])
		{
			q.push(make_pair(next, res + "S"));
			check[next] = true;
		}

		next = left(node); // 3�� ����(L)
		if (!check[next])
		{
			q.push(make_pair(next, res + "L"));
			check[next] = true;
		}

		next = right(node); // 4�� ����(R)
		if (!check[next])
		{
			q.push(make_pair(next, res + "R"));
			check[next] = true;
		}
	
	}


}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n, goal;
		cin >> n >> goal;
		bfs(n, goal);
	}
	cout << '\n';
}