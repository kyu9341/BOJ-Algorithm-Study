#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
vector<int> a[20001];
int check[20001] = { 0 }; // 0 : �湮 x, 1 : 1�� �׷쿡 ����, 2 : 2�� �׷쿡 ����

bool dfs(int node, int c) // c : ���� �湮�� ����� �׷� ( 1 or 2 ) , �̺б׷����̸� true, �ƴϸ� false
{
	check[node] = c; // c �׷� �湮 ó��
	
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i]; // ���� ���
		if (!check[next]) // ���� ������ �湮 �������� ����
		{
			if (!dfs(next, 3 - c)) // ���� ���� ���� �׷��� 1�̶�� 2, 2��� 1
				return false; // false�� ���Ϲ޾����� false����
		}
		else if (check[next] == check[node]) // ���� ������ �̹� �湮�ߴ� �����ε� ���� ������ ���� �׷��̸� �̺б׷����� �ƴ�
			return false;
	}
	return true;
}

bool bfs(int start, int c)
{
	queue<int> q;
	check[start] = c; // �׷� ����
	q.push(start); // ù ��� push

	while (!q.empty())
	{
		int node = q.front();
		q.pop(); 

		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (check[next] == 0)
			{
				c = 3 - check[node]; 
				check[next] = c; // ���� ���� ���� �׷��� 1�̶�� 2, 2��� 1�� �湮 ó��
				q.push(next); // �湮ó���ϸ� push
			}
			else if (check[node] == check[next])
			{
				return false;
			}
		}
	}
	return true;
}

int main(void)
{
	int k; // testcase
	cin >> k;

	while (k--)
	{
		int v, e;
		cin >> v >> e;

		for (int i = 1; i <= v; i++)
		{
			a[i].clear(); // ���� ��� �ʱ�ȭ
			check[i] = 0; // �湮 ���� �ʱ�ȭ
		}

		for (int i = 0; i < e; i++)
		{
			int n, m;
			cin >> n >> m;
			a[n].push_back(m);
			a[m].push_back(n);
		}

		bool ok = true;
		for (int i = 1; i <= v; i++) // ��� ������ Ȯ���Ͽ� �̺� �׷����� �ƴ� ��찡 �ִ��� Ȯ��
		{
			if (check[i] == 0) // ���� �湮 ���� ��忡 ���ؼ� Ȯ��
			{
				if (bfs(i, 1) == false) // dfs(i, 1) �� ����
					ok = false;
			}
			
		}

		if (ok)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

}