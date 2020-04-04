# Problem 14427

## 수열과 쿼리 15

### 문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

- 1 i v : Ai를 v로 바꾼다. (1 ≤ i ≤ N, 1 ≤ v ≤ 109)
- 2 : 수열에서 크기가 가장 작은 값의 인덱스를 출력한다. 그러한 값이 여러개인 경우에는 인덱스가 작은 것을 출력한다.
수열의 인덱스는 1부터 시작한다.
### 입력
첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)

넷째 줄부터 M개의 줄에는 쿼리가 주어진다.

### 출력
2번 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/14427>

### 예제 입력 1
5
5 4 3 2 1
5
2
1 5 3
2
1 4 3
2

### 예제 출력 1
5
4
3

### solve
- 세그먼트 트리를 이용하여 각 노드에 더 자식 노드 중 더 작은 값의 인덱스를 저장한다.
	- minIndex라는 함수를 생성하여 두 인덱스를 받아 더 작은 값을 가지는 인덱스를 리턴한다.
	- 이 때, 두 값이 같은 경우 더 작은 인덱스를 리턴한다.
- 2번 쿼리를 수행하는 경우 세그먼트 트리의 1번 노드에 최솟값의 인덱스가 저장되어 있으므로 tree[1] + 1을 출력한다.(인덱스는 0부터 저장했음)
- 1번 쿼리의 경우 update함수에서 minIndex함수를 사용해서 수정된 노드와 이어지는 노드들을 모두 수정한다.
	- 범위를 벗어나거나 리프 노드에서 수정할 인덱스를 찾았다면 현재 노드의 값(a의 인덱스)를 리턴
	- 왼쪽, 오른쪽 자식 노드로 나누어 재귀를 수행하며 더 작은 값을 가지는 인덱스를 현재 노드에 저장(수정)



### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int tree[MAX * 4 + 1];

int minIndex(int x, int y) // 두 인덱스를 받아 더 작은 값을 가지는 인덱스를 리턴
{
	if (a[x] == a[y]) return x < y ? x : y; // 같은 경우 더 작은 인덱스를 리턴
	return a[x] < a[y] ? x : y;
}

int init(int start, int end, int node)
{ // 자식 노드 중 작은 값의 인덱스를 부모 노드에 저장하는 세그먼트 트리
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;
	// 더 작은 값의 인덱스를 각 노드에 저장
	return tree[node] = minIndex(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index)
{ // 범위를 벗어나거나 수정할 인덱스를 찾았다면 현재 노드 리턴
	if (index < start || index > end || start == end) return tree[node];

	int mid = (start + end) / 2;
	// 더 작은 값을 가지는 인덱스를 현재 노드에 저장
	return tree[node] = minIndex(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;

	init(0, n - 1, 1); // 세그먼트 트리 생성

	while (m--)
	{
		int q, index, value;
		cin >> q;
		if (q == 1)
		{ // 수정하는 경우
			cin >> index >> value;
			index--;
			a[index] = value;
			update(0, n - 1, 1, index);
		}
		if (q == 2)
		{ // 트리의 1번 노드가 최소값의 인덱스
			cout << tree[1] + 1 << '\n';
		}
	}

}

```
