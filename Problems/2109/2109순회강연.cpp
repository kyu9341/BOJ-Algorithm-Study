#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;

int main(void)
{
	int n; // ������ ����
	cin >> n;

	vector<pair<int, int>> uni(n); // first : day, second : pay
	for (int i = 0; i < n; i++)
		cin >> uni[i].second >> uni[i].first;

	sort(uni.begin(), uni.end(), [&](pair<int, int> a, pair<int, int> b)
		{
			return a.first > b.first;
		}); // day���� ��������

	priority_queue<int> pq;

	int ans = 0;
	int uniIdx = 0;
	for (int i = 10000; i >= 1; i--) // �ִ� ��¥����
	{
		while (uniIdx < n && i <= uni[uniIdx].first) // ���� ��¥�� ���� ��¥ �̻��� ���
		{
			pq.push(uni[uniIdx++].second); // �켱���� ť�� ����
		}
		if (!pq.empty())
		{
			ans += pq.top(); // ���� ������ �ĺ��� �� ���� ����� ū ���� ����
			pq.pop();
		}
	}

	cout << ans << '\n';
}