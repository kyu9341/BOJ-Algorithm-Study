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