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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	vector<pair<int, int>> g(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i != 0)
		{
			g[i].first = a[i] - a[i - 1]; // �� ���� ���� ����
			g[i].second = i; // �� ��° ���� �������� ���� ����(i, i - 1)
		}
			
	}
	// Ű ���̸� �������� �������� ����
	sort(g.begin(), g.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; }); 

	int ans = 0;
	int tmp = 0;
	vector<int> t(k - 1);
	for (int i = 0; i < k - 1; i++)
		t[i] = g[i].second; // ������ ���� ������ ����
	sort(t.begin(), t.end()); // ������������ ����
	t.push_back(n); // ������ �ε��� �߰�

	for (int i = 0; i < t.size(); i++)
	{
		ans += (a[t[i] - 1] - a[tmp]);
		tmp = t[i];
	}
	cout << ans << '\n';


}