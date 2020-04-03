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