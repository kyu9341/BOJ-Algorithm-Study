# Problem 13537

## 수열과 쿼리 1

### 문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

- i j k: Ai, Ai+1, ..., Aj로 이루어진 부분 수열 중에서 k보다 큰 원소의 개수를 출력한다.

### 입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.

넷째 줄부터 M개의 줄에는 쿼리 i, j, k가 한 줄에 하나씩 주어진다. (1 ≤ i ≤ j ≤ N, 1 ≤ k ≤ 109)

### 출력
각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/13537>

### 예제 입력 1
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2

### 예제 출력 1
2
0
3

### solve
- 세그먼트 트리를 이용하여 리프 노드가 아닌 각 노드에 자식 노드들을 원소로 가지는 벡터를 저장한다.
	- 원소를 하나씩 입력받을 때마다 트리에 추가하며 알맞은 index를 찾아가며 지나는 노드에 현재 원소를 추가한다.
	- 머지 소트의 모습과 유사하게 트리가 구성된다.
- 트리가 완성되면 각 트리의 노드를 정렬한다.
- 쿼리가 입력되면 query함수에서 k보다 큰 값의 개수를 리턴해준다.
	- 범위를 완전히 벗어난 경우 0을 리턴하고
	- 현재 노드에서 범위 안에 완벽하게 들어온 경우에 현재 노드의 벡터의 end()에서 upper_bound를 사용하여 k보다 큰 첫 번째 인덱스를 빼주어 k보다 큰 값의 개수를 구해 리턴한다.
	


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
vector<int> tree[MAX * 4 + 1];

void update(int start, int end, int node, int index, int x)
{ // 원소를 하나씩 추가하며 세그먼트 트리 구성
	// 리프 노드가 아닌 각 노드에 자식 노드들을 원소로 가지는 벡터를 저장
	if (start > index || end < index) return;
	tree[node].push_back(x);
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, x);
	update(mid + 1, end, node * 2 + 1, index, x);
}

int query(int start, int end, int node, int left, int right, int k)
{
	if (start > right || end < left) return 0;
	// 범위 안에 들어온 경우 더 큰 값들의 개수를 리턴
	if (left <= start && end <= right) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	int mid = (start + end) / 2;
	// 더 큰 값들의 개수를 더해 리턴
	return query(start, mid, node * 2, left, right, k) + query(mid + 1, end, node * 2 + 1, left, right, k);
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(1, n, 1, i, a[i]); // 트리 구성
	}

	for (int i = 1; i <= MAX * 4; i++) // 모든 노드 정렬
		sort(tree[i].begin(), tree[i].end());

	cin >> m;
	while (m--)
	{
		int left, right, k;
		cin >> left >> right >> k;

		cout << query(1, n, 1, left, right, k) << '\n';
	}
}

```
