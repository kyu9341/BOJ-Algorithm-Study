#include<iostream>
#include<queue>

using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	queue<int> q; // 초기 큐
	queue<int> res; // 요세푸스 순열 큐

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q.push(i); // 초기 큐 생성

	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front()); // 큐의 맨 앞 원소를 맨 뒤로 이동
			q.pop();
		}
		res.push(q.front()); // k 번째 원소는 결과 큐에 푸쉬
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
			cout << res.front() << ", "; // ', '으로 하면 안됨(문자열)
			res.pop();
		}
	}
	cout << '>' << '\n';

	return 0;
}