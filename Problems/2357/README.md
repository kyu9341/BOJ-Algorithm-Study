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
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int tree[MAX * 4 + 1];

int minIndex(int x, int y) // 더 작은 값의 인덱스를 반환하는 함수
{
	// 유효하지 않은 경우
	if (x == -1) return y;
	if (y == -1) return x;
	// 같은 경우 더 작은 인덱스 리턴
	if (a[x] == a[y]) return x < y ? x : y;
	else return a[x] <= a[y] ? x : y;
}

int init(int start, int end, int node)
{
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;

	return tree[node] = minIndex(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index)
{	// index를 찾았거나 범위를 벗어난 경우 현재 노드 리턴
	if (start > index || end < index) return tree[node];
	if (start == end) return tree[node];

	int mid = (start + end) / 2;
	// 더 작은 값을 가지는 인덱스로 update
	return tree[node] = minIndex(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
}

int query(int start, int end, int node, int left, int right)
{
	// 구간을 벗어나는 경우
	if (start > right || end < left) return -1;
	// 완전히 구간 안에 들어온 경우
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	// 더 작은 값을 가지는 인덱스 리턴
	return minIndex(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
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
	cin >> m;

	init(1, n, 1);

	while (m--)
	{
		int q, index, v, left, right;
		cin >> q;
		if (q == 1)
		{
			cin >> index >> v;
			a[index] = v;
			update(1, n, 1, index);
		}
		if (q == 2)
		{
			cin >> left >> right;
			cout << query(1, n, 1, left, right) << '\n';
		}
	}

}
```
