#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int tree[MAX * 4 + 1];

int minIndex(int x, int y) // �� �ε����� �޾� �� ���� ���� ������ �ε����� ����
{
	if (a[x] == a[y]) return x < y ? x : y; // ���� ��� �� ���� �ε����� ����
	return a[x] < a[y] ? x : y;
}

int init(int start, int end, int node)
{ // �ڽ� ��� �� ���� ���� �ε����� �θ� ��忡 �����ϴ� ���׸�Ʈ Ʈ��
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;
	// �� ���� ���� �ε����� �� ��忡 ����
	return tree[node] = minIndex(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index)
{ // ������ ����ų� ������ �ε����� ã�Ҵٸ� ���� ��� ����
	if (index < start || index > end || start == end) return tree[node];
	
	int mid = (start + end) / 2;
	// �� ���� ���� ������ �ε����� ���� ��忡 ����
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

	init(0, n - 1, 1); // ���׸�Ʈ Ʈ�� ����

	while (m--)
	{
		int q, index, value;
		cin >> q;
		if (q == 1)
		{ // �����ϴ� ���
			cin >> index >> value;
			index--;
			a[index] = value;
			update(0, n - 1, 1, index);
		}
		if (q == 2)
		{ // Ʈ���� 1�� ��尡 �ּҰ��� �ε���
			cout << tree[1] + 1 << '\n'; 
		}
	}

}