#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;
const int MAX = 300000;

struct gem
{
	int weight, price;
};

bool compare(gem u, gem v)
{
	return u.weight < v.weight; // ���Կ� ���� ��������
}
int main(void)
{
	int n, k; // ������ ����, ������ ����
	cin >> n >> k;
	vector<gem> a(n);
	vector<int> c(k); // ������ �ִ� ����

	for (int i = 0; i < n; i++)
		cin >> a[i].weight >> a[i].price;
	
	for (int i = 0; i < k; i++)
		cin >> c[i];

	sort(a.begin(), a.end(), compare); // ���԰� ������ ��
	sort(c.begin(), c.end()); // ������ ���� ��

	priority_queue <int> pq; // �ִ� ��

	int gemidx = 0; // ������ �ε���
	long long ans = 0;
	for (int i = 0; i < k; i++)
	{
		while (gemidx < n && c[i] >= a[gemidx].weight) // ������ �ѹ����� Ȯ���ϱ� ���� gemidx���
		{ // i��° ������ ���Ժ��� �۰ų� ���� ������ ��� �켱���� ť�� ����
			pq.push(a[gemidx++].price);
		}
		if (!pq.empty())
		{
			ans += (long long)pq.top(); // ������ (�ִ��� ����)
			pq.pop();
		}

	}
	cout << ans << '\n';
}