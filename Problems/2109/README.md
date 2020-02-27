# Problem 2109

## 순회강연

### 문제
한 저명한 학자에게 n(0≤n≤10,000)개의 대학에서 강연 요청을 해 왔다. 각 대학에서는 d(1≤d≤10,000)일 안에 와서 강연을 해 주면 p(1≤p≤10,000)만큼의 강연료를 지불하겠다고 알려왔다. 각 대학에서 제시하는 d와 p값은 서로 다를 수도 있다. 이 학자는 이를 바탕으로, 가장 많은 돈을 벌 수 있도록 순회강연을 하려 한다. 강연의 특성상, 이 학자는 하루에 최대 한 곳에서만 강연을 할 수 있다.

예를 들어 네 대학에서 제시한 p값이 각각 50, 10, 20, 30이고, d값이 차례로 2, 1, 2, 1 이라고 하자. 이럴 때에는 첫째 날에 4번 대학에서 강연을 하고, 둘째 날에 1번 대학에서 강연을 하면 80만큼의 돈을 벌 수 있다.

### 입력
첫째 줄에 정수 n이 주어진다. 다음 n개의 줄에는 각 대학에서 제시한 p값과 d값이 주어진다.

### 출력
첫째 줄에 최대로 벌 수 있는 돈을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2109>

### 예제 입력 1
7
20 1
2 1
10 3
100 2
8 2
5 20
50 10

### 예제 출력 1
185

### solve
- 이 문제도 보석 도둑 문제와 비슷하게 그리디 알고리즘으로 해결이 가능하다.
- 제한 날짜가 현재 날짜 이상인 경우 강연 가능한 호부 중 가장 비용의 큰 것을 누적시키면 된다.
- 우선순위 큐를 사용하여 최대 날짜인 10000일 부터 역으로 내려오며 제한 날짜가 현재 날짜 이상인 모든 강연을 우선순위 큐에 push한다.
	- 예를 들어, 강연이 (20,1),(2,1),(10,3),(100,2),(25,2) 와 같이 있다면
	- (10,3),3,(100,2),(25,2),2,(20,1),(2,1),1 처럼 각 날짜 이상인 강의가 후보가 된다.
- 최대 힙을 이용하였으므로 가장 큰 비용을 가지는 강연이 top()에 있으므로 최대 날짜부터 내려오며 top()의 비용을 누적하면 된다.

### 코드 설명
```C++
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

```
