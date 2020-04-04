#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
vector<int> tree[MAX * 4 + 1];

void update(int start, int end, int node, int index, int x)
{ // ���Ҹ� �ϳ��� �߰��ϸ� ���׸�Ʈ Ʈ�� ����
	// ���� ��尡 �ƴ� �� ��忡 �ڽ� ������ ���ҷ� ������ ���͸� ����
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
	// ���� �ȿ� ���� ��� �� ū ������ ������ ����
	if (left <= start && end <= right) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	int mid = (start + end) / 2;
	// �� ū ������ ������ ���� ����
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
		update(1, n, 1, i, a[i]); // Ʈ�� ����
	}

	for (int i = 1; i <= MAX * 4; i++) // ��� ��� ����
		sort(tree[i].begin(), tree[i].end());

	cin >> m;
	while (m--)
	{
		int left, right, k;
		cin >> left >> right >> k;

		cout << query(1, n, 1, left, right, k) << '\n';
	}
}
