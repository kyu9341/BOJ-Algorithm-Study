# Problem 2042

## 구간 합 구하기

### 문제
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

### 입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력하면 된다.

입력으로 주어지는 모든 수는 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

### 출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 -2^63보다 크거나 같고, 2^63-1보다 작거나 같은 정수이다.


### 문제 링크
<https://www.acmicpc.net/problem/2042>

### 예제 입력 1
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5

### 예제 출력 1
17
12

### solve
- 세그먼트 트리를 이용하여 구간 합을 구하는 문제이다.
- 트리의 각 노드에 모든 하위 노드의 합을 저장하여 구간합을 구한다.
- 자세한 설명은 주석에 있다.


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

ll init(vector<ll> &a, vector<ll> &tree, int start, int end, int node)
{ // 세그먼트 트리 생성
	if (start == end) return tree[node] = a[start]; // 리프 노드에 도달한 경우
	int mid = (start + end) / 2;
	// 재귀적으로 두 부분을 나누어 그 합을 자기 자신으로 한다.
	return tree[node] = init(a, tree, start, mid, node * 2) + init(a, tree, mid + 1, end, node * 2 + 1);
}

// left ~ right 까지의 구간합을 구함, start, end : 시작, 끝 인덱스
ll sum(vector<ll>& tree, int start, int end, int node, int left, int right)
{
	// 범위를 벗어난 경우
	if (left > end || right < start) return 0;
	// 범위 내에 포함된 경우 현재 트리의 값 리턴(구간합)
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	return sum(tree, start, mid, node * 2, left, right) + sum(tree, mid + 1, end, node * 2 + 1, left, right);
}

// index : 수정할 노드의 인덱스, dif : 노드의 차이값
void update(vector<ll>& tree, int start, int end, int node, int index, ll dif)
{
	// 범위를 벗어난 경우
	if (index < start || index > end) return;
	tree[node] += dif; // 수정할 노드가 포함된 노드들의 값을 수정
	if (start == end) return; // 수정할 노드를 찾은 경우
	int mid = (start + end) / 2;
	update(tree, start, mid, node * 2, index, dif);
	update(tree, mid + 1, end, node * 2 + 1, index, dif);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	int h = (int)ceil(log2(n)); // 트리의 높이
	int tree_size = (1 << (h + 1)); // 세그먼트 트리의 크기
	vector<ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	init(a, tree, 0, n - 1, 1); // 세그먼트 트리 생성
	k += m; // m + k번 반복
	while (k--)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (t1 == 1)
		{
			t2--; // 인덱스로 맞춤
			ll dif = (ll)(t3 - a[t2]); // 차이값 저장
			a[t2] = t3; // a[t2] 값 변경
			update(tree, 0, n - 1, 1, t2, dif);
		}
		else if (t1 == 2)
		{
			cout << sum(tree, 0, n - 1, 1, t2 - 1, t3 - 1) << '\n';
		}
	}
}

```
