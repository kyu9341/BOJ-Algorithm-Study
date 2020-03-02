#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<utility>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	priority_queue<int> pq; // ����� ���� �켱���� ť
	priority_queue<int, vector<int>, greater<int>> mq; // ������ ���� �켱���� ť

	for (int i = 0; i < n; i++) // ����� ������ �����Ͽ� �켱���� ť�� ���� 0�� ������ ����
	{
		int m;
		cin >> m;
		if (m > 0)
			pq.push(m);
		else
			mq.push(m);
	}

	int ans = 0;

	while (pq.size() > 1) // ��� ť����
	{
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();

		if (x * y >= x + y) // ū ������ �� ���� �̾� ���� ���� ���� ������ ũ�ٸ� 
			ans += x * y; // ���� �� ����
		else
			ans += x + y;
	}
	if (!pq.empty()) // ��� ť�� ���� Ȧ�� ����� 
	{
		int r = pq.top(); // ���� �� ó��
		pq.pop();
		ans += r;
	}

	while (mq.size() > 1) // ���� ť����
	{
		int x = mq.top();
		mq.pop();
		int y = mq.top();
		mq.pop();
		 // ������ ū ���������� ���� �����ؾ� �ִ��� ���� �� ����
		if (x * y >= x + y) // ���� ������ �� ���� �̾� ���� ���� ���� ������ ũ�ٸ�
			ans += x * y; // ���� �� ����
		else
			ans += x + y;
	}
	if (!mq.empty()) // ���� ť�� ���Ұ� Ȧ�� �����
	{
		int r = mq.top(); // ���� �� ó��
		mq.pop();
		ans += r;
	}

	cout << ans << '\n';
}