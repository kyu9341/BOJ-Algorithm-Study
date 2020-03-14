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
			g[i].first = a[i] - a[i - 1]; // 각 수의 차를 저장
			g[i].second = i; // 몇 번째 수의 차이인지 같이 저장(i, i - 1)
		}
			
	}
	// 키 차이를 기준으로 내림차순 정렬
	sort(g.begin(), g.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; }); 

	int ans = 0;
	int tmp = 0;
	vector<int> t(k - 1);
	for (int i = 0; i < k - 1; i++)
		t[i] = g[i].second; // 구간을 나눌 지점을 저장
	sort(t.begin(), t.end()); // 오름차순으로 정렬
	t.push_back(n); // 마지막 인덱스 추가

	for (int i = 0; i < t.size(); i++)
	{
		ans += (a[t[i] - 1] - a[tmp]);
		tmp = t[i];
	}
	cout << ans << '\n';


}