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

	priority_queue<int> pq; // 양수를 담을 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> mq; // 음수를 담을 우선순위 큐

	for (int i = 0; i < n; i++) // 양수와 음수를 구분하여 우선순위 큐에 담음 0은 음수에 포함
	{
		int m;
		cin >> m;
		if (m > 0)
			pq.push(m);
		else
			mq.push(m);
	}

	int ans = 0;

	while (pq.size() > 1) // 양수 큐에서
	{
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();

		if (x * y >= x + y) // 큰 수부터 두 개씩 뽑아 곱한 값이 더한 값보다 크다면 
			ans += x * y; // 곱한 값 누적
		else
			ans += x + y;
	}
	if (!pq.empty()) // 양수 큐의 수가 홀수 개라면 
	{
		int r = pq.top(); // 남은 수 처리
		pq.pop();
		ans += r;
	}

	while (mq.size() > 1) // 음수 큐에서
	{
		int x = mq.top();
		mq.pop();
		int y = mq.top();
		mq.pop();
		 // 절댓값이 큰 음수끼리의 곱을 누적해야 최댓값을 구할 수 있음
		if (x * y >= x + y) // 작은 수부터 두 개씩 뽑아 곱한 값이 더한 값보다 크다면
			ans += x * y; // 곱한 값 누적
		else
			ans += x + y;
	}
	if (!mq.empty()) // 음수 큐의 원소가 홀수 개라면
	{
		int r = mq.top(); // 남은 수 처리
		mq.pop();
		ans += r;
	}

	cout << ans << '\n';
}