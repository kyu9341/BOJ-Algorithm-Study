#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
vector<int> tree[MAX * 4 + 1];

void init(int start, int end, int node, int index, int x)
{	// ���� ��Ʈ Ʈ�� ���� ( �� ��忡 ���� ��忡 ���ԵǴ� ���� ��� ���� ���·� ���� )
	if (start > index || index > end) return;
	tree[node].push_back(x);
	if (start == end) return;
	int mid = (start + end) >> 1;

	init(start, mid, node * 2, index, x);
	init(mid + 1, end, node * 2 + 1, index, x);

}

int query(int start, int end, int node, int left, int right, int k)
{	// ������ ��� ��� 0�� ����
	if (start > right || end < left) return 0;
	// ���� ���� ������ ���� ��� k���� ū ���� ������ ����
	if (left <= start && end <= right) // ������ end()�ε������� k���� ū ���� ����� ���� �ε����� ���� ����
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
	// ���� ��Ʈ Ʈ���� �� ��带 ����
	for (int i = 1; i <= MAX * 4; i++)
		sort(tree[i].begin(), tree[i].end());

	int last_ans = 0;
	cin >> m;
	while (m--)
	{
		int left, right, k;
		cin >> left >> right >> k;
		// ���� ���� �信 xor������ ����
		left ^= last_ans;
		right ^= last_ans;
		k ^= last_ans;
		// ���� ���� �� ���� ������ ���
		last_ans = query(1, n, 1, left, right, k);
		cout << last_ans << '\n';
	}
	

}