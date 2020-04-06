# Problem 16975

## 수열과 쿼리 21

### 문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

- 1 i j k: Ai, Ai+1, ..., Aj에 k를 더한다.
- 2 x: Ax 를 출력한다.

### 입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 1,000,000)

셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.

넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. 1번 쿼리의 경우 1 ≤ i ≤ j ≤ N, -1,000,000 ≤ k ≤ 1,000,000 이고, 2번 쿼리의 경우 1 ≤ x ≤ N이다. 2번 쿼리는 하나 이상 주어진다.

### 출력
2번 쿼리가 주어질 때마다 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/16975>

### 예제 입력 1
5
1 2 3 4 5
4
1 3 4 6
2 3
1 1 3 -2
2 3

### 예제 출력 1
9
7

### solve
- 세그먼트 트리를 이용하여 해결하였다.
- 리프 노드를 제외한 나머지 노드를 0으로 초기화한다.
- 1번 쿼리인 경우 update함수에서
  - 범위를 벗어난다면 현재 노드를 리턴하고
  - 완전히 범위 내에 들어온 경우 각 노드에 더해질 k값들을 모두 누적하여 쿼리 수행 시 거쳐가는 모든 노드의 값을 더할 수 있도록 구성한다.
- 2번 쿼리를 수행하는 경우
 	- 리프 노드까지 이동하며 지금까지 각 노드에 누적된 값을 모두 더하여 리턴한다.


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

const int MAX = 100000;
// 값이 누적되면 정수 범위를 벗어나므로 long long형으로 선언
ll a[MAX + 1];
ll tree[MAX * 4];

void init(int start, int end, int node)
{	// 세그먼트 트리 생성 리프 노드를 제외한 나머지 노드는 0으로 초기화
	if (start == end)
	{
		tree[node] = a[start];
		return;
	}
	tree[node] = 0;
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int left, int right, ll k)
{	// 각 노드에 더해질 k값들을 모두 누적하여 쿼리 수행 시 거쳐가는 모든 노드의 값을 더할 수 있도록 구성.
	// 범위를 벗어난 경우 리턴
	if (start > right || end < left) return;
	// 완전히 범위 내에 들어온 경우 현재 노드에 k를 누적
	if (left <= start && end <= right)
	{
		tree[node] += k;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, k);
	update(mid + 1, end, node * 2 + 1, left, right, k);
}

ll getX(int start, int end, int node, int index, ll ans)
{	// index에 맞는 리프 노드까지 이동하며 거치는 노드의 값을 모두 누적한다.
	if (index < start || index > end) return 0;
	ans += tree[node];
	if (start == end) return ans; // 리프 노드에 도달하면 누적된 값 리턴
	int mid = (start + end) / 2;
	return getX(start, mid, node * 2, index, ans) + getX(mid + 1, end, node * 2 + 1, index, ans);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	init(1, n, 1);
	cin >> m;

	while (m--)
	{
		int q, left, right, index;
		ll k;
		cin >> q;
		if (q == 1)
		{
			cin >> left >> right >> k;
			update(1, n, 1, left, right, k);
		}
		if (q == 2)
		{
			cin >> index;
			cout << getX(1, n, 1, index, 0) <<'\n';
		}
	}

}
```
