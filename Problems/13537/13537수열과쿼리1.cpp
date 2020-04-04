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
