# Problem 13549

## 숨바꼭질 3

### 문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

### 입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

### 출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/13549>

### 예제 입력 1
5 17

### 예제 출력 1
2


### solve
- 숨바꼭질 문제와 거의 똑같은 문제인데 순간이동을 하는 경우 시간이 걸리지 않는 점이 다르다.
- 숨바꼭질 문제와 마찬가지로 bfs를 이용하여 풀었는데 틀리다고 나와 순간이동 하는 경우를 먼저 처리하도록 하니 맞았다.
- 순간이동(0초)이 걷는 것(1초)보다 빠르기 때문에 우선순위가 높다. 이러한 이유로 먼저 처리해야 하는 것이었다.
- 단순히 bfs를 이용하여 풀려면 모든 간선의 가중치가 동일해야 한다.
- 그래서 이 문제는 덱을 이용하여 간선의 가중치가 0이면 큐의 맨 앞에 넣고, 1이라면 큐의 맨 뒤에 넣는 방식으로 해결이 가능하다.


### 코드 설명
```C++
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;
const int MAX = 100000;
bool check[MAX + 1];
int dist[MAX + 1];

int main(void)
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	dist[n] = 0;
	check[n] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now * 2 <= MAX && check[now * 2] == false) // x * 2로 순간이동 하는 경우
		{
			q.push(now * 2);
			dist[now * 2] = dist[now];
			check[now * 2] = true;
		}

		if (now - 1 >= 0 && check[now - 1] == false) // x - 1로 이동하는 경우
		{
			q.push(now - 1);
			dist[now - 1] = dist[now] + 1;
			check[now - 1] = true;
		}
		if (now + 1 <= MAX && check[now + 1] == false) // x + 1로 이동하는 경우
		{
			q.push(now + 1);
			dist[now + 1] = dist[now] + 1;
			check[now + 1] = true;
		}


	}
	cout << dist[k] << '\n';

}

```
- 덱(deque)사용
```C++
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<deque>

using namespace std;
const int MAX = 100000;
bool check[MAX + 1];
int dist[MAX + 1];

int main(void)
{
	int n, k;
	cin >> n >> k;

	deque<int> q; // 덱 사용
	q.push_back(n);
	dist[n] = 0;
	check[n] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop_front();

		if (now * 2 <= MAX && check[now * 2] == false) // x * 2로 순간이동 하는 경우
		{
			q.push_front(now * 2); // 순간이동인 경우 우선순위가 더 높으므로 덱의 맨 앞에 push
			dist[now * 2] = dist[now];
			check[now * 2] = true;
		}

		if (now - 1 >= 0 && check[now - 1] == false) // x - 1로 이동하는 경우
		{
			q.push_back(now - 1);
			dist[now - 1] = dist[now] + 1;
			check[now - 1] = true;
		}
		if (now + 1 <= MAX && check[now + 1] == false) // x + 1로 이동하는 경우
		{
			q.push_back(now + 1);
			dist[now + 1] = dist[now] + 1;
			check[now + 1] = true;
		}


	}
	cout << dist[k] << '\n';

}
```
