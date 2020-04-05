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