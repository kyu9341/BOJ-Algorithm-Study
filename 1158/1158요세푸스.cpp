#include<iostream>
#include<queue>

using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	queue<int> q; // �ʱ� ť
	queue<int> res; // �似Ǫ�� ���� ť

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q.push(i); // �ʱ� ť ����

	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front()); // ť�� �� �� ���Ҹ� �� �ڷ� �̵�
			q.pop();
		}
		res.push(q.front()); // k ��° ���Ҵ� ��� ť�� Ǫ��
		q.pop();
	}
	cout << '<';

	while (!res.empty())
	{
		if (res.size() == 1)
		{
			cout << res.front();
			res.pop();
		}
		else
		{
			cout << res.front() << ", "; // ', '���� �ϸ� �ȵ�(���ڿ�)
			res.pop();
		}
	}
	cout << '>' << '\n';

	return 0;
}