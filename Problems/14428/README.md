# Problem 14428

## 수열과 쿼리 16

### 문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

- 1 i v : Ai를 v로 바꾼다.
- 2 i j : Ai, Ai+1, ..., Aj에서 크기가 가장 작은 값의 인덱스를 출력한다. 그러한 값이 여러개인 경우에는 인덱스가 작은 것을 출력한다.
수열의 인덱스는 1부터 시작한다.

### 입력
첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)

넷째 줄부터 M개의 줄에는 쿼리가 주어진다.

### 출력
2번 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/14428>

### 예제 입력 1
5
5 4 3 2 1
6
2 1 3
2 1 4
1 5 3
2 3 5
1 4 3
2 3 5

### 예제 출력 1
3
4
4
3

### solve
- 수열과 쿼리 15문제와 아주 유사하다. 2번 쿼리 시 범위가 주어지는 것이 다르다.
- 세그먼트 트리를 이용하여 각 노드에 더 자식 노드 중 더 작은 값의 인덱스를 저장한다.
	- minIndex라는 함수를 생성하여 두 인덱스를 받아 더 작은 값을 가지는 인덱스를 리턴한다.
	- 이 때, 두 값이 같은 경우 더 작은 인덱스를 리턴한다.
- 2번 쿼리를 수행하는 경우 query함수에서 지정해준 범위를 벗어나면 -1을 리턴하고, 완전히 현재 구간이 지정해준 범위 내에 들어온다면 현재 노드의 값(하위 노드 중 최솟값을 가지는 인덱스)을 리턴한다.
- 1번 쿼리의 경우 update함수에서 minIndex함수를 사용해서 수정된 노드와 이어지는 노드들을 모두 수정한다.
	- 범위를 벗어나거나 리프 노드에서 수정할 인덱스를 찾았다면 현재 노드의 값(a의 인덱스)를 리턴
	- 왼쪽, 오른쪽 자식 노드로 나누어 재귀를 수행하며 더 작은 값을 가지는 인덱스를 현재 노드에 저장(수정)



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
