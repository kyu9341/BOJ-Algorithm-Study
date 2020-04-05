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