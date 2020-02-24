#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<deque>
#include<cstdio>

using namespace std;

struct Node // ����ü�� Ʈ�� ����
{
	int left;
	int right;
};
Node a[50];

void preorder(int x) // ��������(���� ��ȸ)
{
	if (x == -1)
		return;
	cout << char(x + 'A'); // ���� ��� ���
	preorder(a[x].left);
	preorder(a[x].right);
}
void inorder(int x) // �ο���(���� ��ȸ)
{
	if (x == -1) // �ڽ� ��尡 ������ ����
		return;
	inorder(a[x].left);
	cout << char(x + 'A');
	inorder(a[x].right);
}
void postorder(int x) // ����Ʈ����(���� ��ȸ)
{
	if (x == -1)
		return;
	postorder(a[x].left);
	postorder(a[x].right);
	cout << char(x + 'A');
}


int main(void)
{
	int n; // ���� Ʈ���� ����� ����
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A'; // �θ� ��� (0���� ����)
		if (y == '.')
			a[x].left = -1; // �ڽ� ��尡 ���� ���
		else
			a[x].left = y - 'A'; // ���� �ڽ� ��� ����(����������)
		if (z == '.')
			a[x].right = -1;
		else
			a[x].right = z - 'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
}