#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<deque>

using namespace std;
const int MAX = 100000;
bool check[MAX + 1];
int dist[MAX + 1];

int main(void)
{
	int n, k;
	cin >> n >> k;

	deque<int> q; // �� ���
	q.push_back(n);
	dist[n] = 0;
	check[n] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop_front();

		if (now * 2 <= MAX && check[now * 2] == false) // x * 2�� �����̵� �ϴ� ���
		{
			q.push_front(now * 2); // �����̵��� ��� �켱������ �� �����Ƿ� ���� �� �տ� push
			dist[now * 2] = dist[now];
			check[now * 2] = true;
		}

		if (now - 1 >= 0 && check[now - 1] == false) // x - 1�� �̵��ϴ� ���
		{
			q.push_back(now - 1);
			dist[now - 1] = dist[now] + 1;
			check[now - 1] = true;
		}
		if (now + 1 <= MAX && check[now + 1] == false) // x + 1�� �̵��ϴ� ���
		{
			q.push_back(now + 1);
			dist[now + 1] = dist[now] + 1;
			check[now + 1] = true;
		}


	}
	cout << dist[k] << '\n';

}