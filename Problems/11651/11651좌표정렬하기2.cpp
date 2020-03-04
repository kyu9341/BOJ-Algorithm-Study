#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end(), [&](pair<int, int> u, pair<int, int> v)
		{
			if (u.second == v.second) return u.first < v.first; // y가 같으면 x에대해 오름차순
			else return u.second < v.second; // y에 대해 오름차순
		});
	for (int i = 0; i < n; i++)
	{
		cout << a[i].first << ' ' << a[i].second;
		cout << '\n';
	}
}