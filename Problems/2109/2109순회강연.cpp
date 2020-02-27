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
	int n; // 대학의 개수
	cin >> n;

	vector<pair<int, int>> uni(n); // first : day, second : pay
	for (int i = 0; i < n; i++)
		cin >> uni[i].second >> uni[i].first;

	sort(uni.begin(), uni.end(), [&](pair<int, int> a, pair<int, int> b)
		{
			return a.first > b.first;
		}); // day기준 내림차순

	priority_queue<int> pq;

	int ans = 0;
	int uniIdx = 0;
	for (int i = 10000; i >= 1; i--) // 최대 날짜부터
	{
		while (uniIdx < n && i <= uni[uniIdx].first) // 제한 날짜가 현재 날짜 이상인 경우
		{
			pq.push(uni[uniIdx++].second); // 우선순위 큐에 삽입
		}
		if (!pq.empty())
		{
			ans += pq.top(); // 강연 가능한 후보들 중 가장 비용이 큰 것을 누적
			pq.pop();
		}
	}

	cout << ans << '\n';
}