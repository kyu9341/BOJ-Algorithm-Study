# Problem 18436

## 수열과 쿼리 37

### 문제
길이가 N인 수열 A1, A2, ..., AN이 있다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

- 1 i x: Ai를 x로 바꾼다.
- 2 l r: l ≤ i ≤ r에 속하는 모든 Ai중에서 짝수의 개수를 출력한다.
- 3 l r: l ≤ i ≤ r에 속하는 모든 Ai중에서 홀수의 개수를 출력한다.
수열의 인덱스는 1부터 시작한다.

### 입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.

넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. (1 ≤ i ≤ N, 1 ≤ l ≤ r ≤ N, 1 ≤ x ≤ 109)

### 출력
2, 3번 쿼리의 정답을 한 줄에 하나씩 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/18436>

### 예제 입력 1
6
1 2 3 4 5 6
4
2 2 5
3 1 4
1 5 4
2 1 6

### 예제 출력 1
2
2
4

### solve
- 세그먼트 트리를 이용하여 리프 노드에 a의 해당 인덱스의 수가 홀수라면 1, 짝수라면 0을 넣는다.
- 홀수의 개수를 각 노드에 저장 (구간에서 홀수의 개수를 빼면 짝수의 개수)
- 1번 쿼리의 경우 트리는 홀짝만 저장하므로 새로 입력된 수(x)가 이전 수와 홀짝이 다른 경우에만 update함수를 수행한다.
	- x가 짝수라면 트리의 현재 노드를 1감소시킨다.(홀수의 개수 1감소)
	- 홀수라면 트리의 현재 노드를 1증가시킨다.(홀수의 개수 1증가)
	- 리프 노드에 도달하면 새로 입력된 수의 홀짝으로 변경
- 2, 3번 쿼리의 경우 각 구간의 홀수의 개수를 리턴한다.
 	- 2번 쿼리(짝수)인 경우 구간의 원소의 개수에서 홀수의 개수를 빼주어 짝수의 개수를 출력한다.
	- 3번 쿼리(홀수)인 경우 바로 홀수의 개수를 출력한다.

### 코드 설명
```C++
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100001;
int a[MAX];

int tree[MAX * 4];

int init(int start, int end, int node) // 세그먼트 트리 구성
{	// 리프 노드에 a의 해당 인덱스의 수가 홀수라면 1, 짝수라면 0을 넣는다.
	if (start == end) return tree[node] = a[start] % 2 == 0 ? 0 : 1;
	int mid = (start + end) >> 1;
	// 홀수의 개수를 각 노드에 저장 (구간에서 홀수의 개수를 빼면 짝수의 개수)
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int index, int x, int value)
{	// 새로 입력된 수가 이전 수와 홀짝이 다른 경우만 실행
	if (start > index || index > end) return;
	if (x % 2 == 0) tree[node]--; // 짝수라면 홀수의 개수를 1감소
	else tree[node]++; // 홀수라면 1증가
	if (start == end)
	{	// 홀짝을 변경
		tree[node] = value;
		return;
	}
	int mid = (start + end) >> 1;

	update(start, mid, node * 2, index, x, value);
	update(mid + 1, end, node * 2 + 1, index, x, value);

}

int query(int start, int end, int node, int left, int right)
{
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node]; // 홀수의 개수를 리턴
	int mid = (start + end) >> 1;

	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
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
		int q, index, x, left, right;
		cin >> q;
		if (q == 1)
		{
			cin >> index >> x;
			// 홀짝이 다른 경우만 update
			if (a[index] % 2 == 0 && x % 2 == 1) update(1, n, 1, index, x, 1); // 홀수로 바뀐 경우
			else if (a[index] % 2 == 1 && x % 2 == 0) update(1, n, 1, index, x, 0); // 짝수로 바뀐 경우
			a[index] = x;
		}
		if (q == 2)
		{
			cin >> left >> right;
			int num = right - left + 1;
			// 구간에서 홀수의 개수를 빼면 짝수의 개수
			cout << num - query(1, n, 1, left, right) << '\n';
		}
		if (q == 3)
		{
			cin >> left >> right;
			// 홀수의 개수
			cout << query(1, n, 1, left, right) << '\n';
		}
	}

}

```
