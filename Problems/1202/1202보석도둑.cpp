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
	return u.weight < v.weight; // 무게에 대해 오름차순
}
int main(void)
{
	int n, k; // 보석의 개수, 가방의 개수
	cin >> n >> k;
	vector<gem> a(n);
	vector<int> c(k); // 가방의 최대 무게

	for (int i = 0; i < n; i++)
		cin >> a[i].weight >> a[i].price;
	
	for (int i = 0; i < k; i++)
		cin >> c[i];

	sort(a.begin(), a.end(), compare); // 무게가 가벼운 순
	sort(c.begin(), c.end()); // 가벼운 가방 순

	priority_queue <int> pq; // 최대 힙

	int gemidx = 0; // 보석의 인덱스
	long long ans = 0;
	for (int i = 0; i < k; i++)
	{
		while (gemidx < n && c[i] >= a[gemidx].weight) // 보석을 한번씩만 확인하기 위해 gemidx사용
		{ // i번째 가방의 무게보다 작거나 같은 보석을 모두 우선순위 큐에 삽입
			pq.push(a[gemidx++].price);
		}
		if (!pq.empty())
		{
			ans += (long long)pq.top(); // 가장위 (최댓값을 누적)
			pq.pop();
		}

	}
	cout << ans << '\n';
}