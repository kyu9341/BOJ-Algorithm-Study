# Problem 14438

## 수열과 쿼리 17

### 문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

- 1 i v : Ai를 v로 바꾼다. (1 ≤ i ≤ N, 1 ≤ v ≤ 109)
- 2 i j : Ai, Ai+1, ..., Aj에서 크기가 가장 작은 값을 출력한다. (1 ≤ i ≤ j ≤ N)
수열의 인덱스는 1부터 시작한다.

### 입력
첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)

넷째 줄부터 M개의 줄에는 쿼리가 주어진다.

### 출력
2번 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/14438>

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
2
2
3

### solve
- 수열과 쿼리 15, 16 문제와 아주 유사하다. 2번 쿼리 수행 시 최솟값을 가지는 인덱스가 아닌 그냥 최솟값을 출력하면 된다. 더 쉬운 문제이다.
- 세그먼트 트리를 이용하여 각 노드에 더 자식 노드 중 더 작은 값을 저장한다.
- 2번 쿼리를 수행하는 경우
 	- query함수에서 지정해준 범위를 벗어나면 INT_MAX 리턴하고,(이 값이 리턴되지 않도록)
	- 완전히 현재 구간이 지정해준 범위 내에 들어온다면 현재 노드의 값(최솟값)을 리턴한다.
- 1번 쿼리의 경우 update함수에서 수정된 노드와 이어지는 노드들을 모두 수정하여 최솟값 세그먼트 트리를 유지한다.
	- 범위를 벗어난다면 현재 노드를 리턴
	- 리프 노드에서 수정할 인덱스를 찾았다면 현재 노드의 값을 수정 후 리턴
	- 왼쪽, 오른쪽 자식 노드로 나누어 재귀를 수행하며 더 작은 값을 가지는 인덱스를 현재 노드에 저장(수정)



### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int tree[MAX * 4];

int init(int start, int end, int node)
{	// 자식 노드 중 더 작은 값을 현재 노드로 하는 세그먼트 트리 생성
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) >> 1;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index)
{
	// 범위를 벗어나면 현재 노드 리턴
	if (start > index || end < index) return tree[node];
	// 리프 노드에 도달하면 값 수정 후 리턴
	if (start == end) return tree[node] = a[index];
	int mid = (start + end) >> 1;
	// 수정된 값으로 최솟값 트리 재구성
	return tree[node] = min(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
}

int query(int start, int end, int node, int left, int right)
{
	// 범위를 벗어난 경우 이 값이 리턴되지 않도록 가장 큰 정수값 리턴
	if (start > right || end < left) return INT_MAX;
	// 완전히 범위에 들어온 경우 현재 노드(최솟값) 리턴
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
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
