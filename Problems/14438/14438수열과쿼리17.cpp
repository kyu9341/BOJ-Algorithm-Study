#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int tree[MAX * 4];

int init(int start, int end, int node)
{	// �ڽ� ��� �� �� ���� ���� ���� ���� �ϴ� ���׸�Ʈ Ʈ�� ����
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) >> 1;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index)
{
	// ������ ����� ���� ��� ����
	if (start > index || end < index) return tree[node];
	// ���� ��忡 �����ϸ� �� ���� �� ����
	if (start == end) return tree[node] = a[index];
	int mid = (start + end) >> 1;
	// ������ ������ �ּڰ� Ʈ�� �籸��
	return tree[node] = min(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
}

int query(int start, int end, int node, int left, int right)
{
	// ������ ��� ��� �� ���� ���ϵ��� �ʵ��� ���� ū ������ ����
	if (start > right || end < left) return INT_MAX;
	// ������ ������ ���� ��� ���� ���(�ּڰ�) ����
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