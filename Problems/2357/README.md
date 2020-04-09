# Problem 2357

## 최솟값과 최댓값

### 문제
N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수, 또는 제일 큰 정수를 찾는 것은 어려운 일이 아니다. 하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 보자.

여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최소, 최댓값을 찾아야 한다. 각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.

### 입력
첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 주어진다.

### 출력
M개의 줄에 입력받은 순서대로 각 a, b에 대한 답을 최솟값, 최댓값 순서로 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2357>

### 예제 입력 1
10 4
75
30
100
38
50
51
52
20
81
5
1 10
3 5
6 9
8 10

### 예제 출력 1
5 100
38 100
20 81
5 81

### solve
- 세그먼트 트리를 이용하여 각 노드에 더 자식 노드 중 더 작은 값과 큰 값을 pair형태로 저장한다.
- 쿼리가 들어오면 query함수로 이동하여
	- 범위를 벗어난 경우 선택되지 않도록 INT_MAX, 0 리턴
	- 범위 내에 완전히 들어온 경우 현재 노드 리턴
	- 좌, 우측 노드로 이동하며 최대, 최솟값을 구해 pair형으로 리턴한다.

### 코드 설명
```C++
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100000;

int a[MAX + 1];
pair<int, int> tree[MAX * 4];

pair<int, int> init(int start, int end, int node)
{ // 각 노드에 자식 노드의 최댓값, 최솟값을 가지는 세그먼트 트리 구성
	if (start == end)
	{ // 리프 노드 도착 시 최대, 최솟값 저장
		tree[node].first = a[start];
		tree[node].second = a[start];
		return tree[node];
	}

	int mid = (start + end) >> 1;
	// 좌측 노드로 이동
	pair<int, int> left = init(start, mid, node * 2);
	// 우측 노드로 이동
	pair<int, int> right = init(mid + 1, end, node * 2 + 1);

	tree[node].first = min(left.first, right.first);
	tree[node].second = max(left.second, right.second);

	return tree[node];
}

pair<int, int> query(int start, int end, int node, int left, int right)
{
	// 범위를 벗어난 경우 선택되지 않도록 INT_MAX, 0 리턴
	if (start > right || end < left) return { INT_MAX, 0 };
	// 범위 내에 완전히 들어온 경우 현재 노드 리턴
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	// 좌, 우측 노드로 이동하며 최대, 최솟값을 구함.
	pair<int, int> l = query(start, mid, node * 2, left, right);
	pair<int, int> r = query(mid + 1, end, node * 2 + 1, left, right);

	pair<int, int> res;
	res.first = min(l.first, r.first);
	res.second = max(l.second, r.second);

	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	init(1, n, 1);

	while (m--)
	{
		int left, right;
		cin >> left >> right;
		pair<int, int> tmp = query(1, n, 1, left, right);
		cout << tmp.first << ' ' << tmp.second << '\n';
	}

}
```
