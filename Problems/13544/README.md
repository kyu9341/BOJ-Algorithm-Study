# Problem 13544

## 수열과 쿼리 3

### 문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

- i j k: Ai, Ai+1, ..., Aj로 이루어진 부분 수열 중에서 k보다 큰 원소의 개수를 출력한다.

### 입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.

넷째 줄부터 M개의 줄에는 a, b, c가 주어진다. a, b, c를 이용해 쿼리를 만들어야 한다.

- i = a xor last_ans
- j = b xor last_ans
- k = c xor last_ans
last_ans는 이전 쿼리의 정답이며, 가장 처음에는 0이다. xor한 결과는 1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 109 을 만족한다.

### 출력
각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/13544>

### 예제 입력 1
5
5 1 2 3 4
3
2 4 1
6 6 6
1 5 2

### 예제 출력 1
2
0
3

### solve
- 수열과 쿼리 1 문제와 똑같지만 xor연산만 추가된 문제이다.
- 세그먼트 트리를 이용하여 리프 노드가 아닌 각 노드에 자식 노드들을 원소로 가지는 벡터를 저장한다.
	- 원소를 하나씩 입력받을 때마다 트리에 추가하며 알맞은 index를 찾아가며 지나는 노드에 현재 원소를 추가한다.
	- 머지 소트의 모습과 유사하게 트리가 구성된다.
- 트리가 완성되면 각 트리의 노드를 정렬한다.
- 쿼리가 입력되면 query함수에서 k보다 큰 값의 개수를 리턴해준다.
	- 쿼리 수행 전 이전 연산의 답을 저장하여 xor연산 후 쿼리를 수행한다.
	- 범위를 완전히 벗어난 경우 0을 리턴하고
	- 현재 노드에서 범위 안에 완벽하게 들어온 경우에 현재 노드의 벡터의 end()에서 upper_bound를 사용하여 k보다 큰 첫 번째 인덱스를 빼주어 k보다 큰 값의 개수를 구해 리턴한다.


### 코드 설명
```C++
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
vector<int> tree[MAX * 4 + 1];

void init(int start, int end, int node, int index, int x)
{	// 머지 소트 트리 구성 ( 각 노드에 하위 노드에 포함되는 값을 모두 벡터 형태로 저장 )
	if (start > index || index > end) return;
	tree[node].push_back(x);
	if (start == end) return;
	int mid = (start + end) >> 1;

	init(start, mid, node * 2, index, x);
	init(mid + 1, end, node * 2 + 1, index, x);

}

int query(int start, int end, int node, int left, int right, int k)
{	// 범위를 벗어난 경우 0을 리턴
	if (start > right || end < left) return 0;
	// 범위 내에 완전히 들어온 경우 k보다 큰 수의 개수를 리턴
	if (left <= start && end <= right) // 벡터의 end()인덱스에서 k보다 큰 가장 가까운 수의 인덱스를 빼서 리턴
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	int mid = (start + end) >> 1;
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
		init(1, n, 1, i, a[i]);
	}
	// 머지 소트 트리의 각 노드를 정렬
	for (int i = 1; i <= MAX * 4; i++)
		sort(tree[i].begin(), tree[i].end());

	int last_ans = 0;
	cin >> m;
	while (m--)
	{
		int left, right, k;
		cin >> left >> right >> k;
		// 각각 이전 답에 xor연산을 수행
		left ^= last_ans;
		right ^= last_ans;
		k ^= last_ans;
		// 쿼리 수행 후 현재 정답을 기록
		last_ans = query(1, n, 1, left, right, k);
		cout << last_ans << '\n';
	}


}

```
