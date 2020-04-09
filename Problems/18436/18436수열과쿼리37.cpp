#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100001;
int a[MAX];

int tree[MAX * 4];

int init(int start, int end, int node) // ���׸�Ʈ Ʈ�� ����
{	// ���� ��忡 a�� �ش� �ε����� ���� Ȧ����� 1, ¦����� 0�� �ִ´�.
	if (start == end) return tree[node] = a[start] % 2 == 0 ? 0 : 1;
	int mid = (start + end) >> 1;
	// Ȧ���� ������ �� ��忡 ���� (�������� Ȧ���� ������ ���� ¦���� ����)
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);	
}

void update(int start, int end, int node, int index, int x, int value)
{	// ���� �Էµ� ���� ���� ���� Ȧ¦�� �ٸ� ��츸 ����
	if (start > index || index > end) return;
	if (x % 2 == 0) tree[node]--; // ¦����� Ȧ���� ������ 1����
	else tree[node]++; // Ȧ����� 1����
	if (start == end)
	{	// Ȧ¦�� ����
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
	if (left <= start && end <= right) return tree[node]; // Ȧ���� ������ ����
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
			// Ȧ¦�� �ٸ� ��츸 update
			if (a[index] % 2 == 0 && x % 2 == 1) update(1, n, 1, index, x, 1); // Ȧ���� �ٲ� ���
			else if (a[index] % 2 == 1 && x % 2 == 0) update(1, n, 1, index, x, 0); // ¦���� �ٲ� ���
			a[index] = x;
		}
		if (q == 2)
		{
			cin >> left >> right;
			int num = right - left + 1;
			// �������� Ȧ���� ������ ���� ¦���� ����
			cout << num - query(1, n, 1, left, right) << '\n';
		}
		if (q == 3)
		{
			cin >> left >> right;
			// Ȧ���� ����
			cout << query(1, n, 1, left, right) << '\n';
		}
	}

}