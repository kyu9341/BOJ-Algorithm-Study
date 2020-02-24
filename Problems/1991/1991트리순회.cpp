#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<deque>
#include<cstdio>

using namespace std;

struct Node // 구조체로 트리 구현
{
	int left;
	int right;
};
Node a[50];

void preorder(int x) // 프리오더(전위 순회)
{
	if (x == -1)
		return;
	cout << char(x + 'A'); // 현재 노드 출력
	preorder(a[x].left);
	preorder(a[x].right);
}
void inorder(int x) // 인오더(중위 순회)
{
	if (x == -1) // 자식 노드가 없으면 리턴
		return;
	inorder(a[x].left);
	cout << char(x + 'A');
	inorder(a[x].right);
}
void postorder(int x) // 포스트오더(후위 순회)
{
	if (x == -1)
		return;
	postorder(a[x].left);
	postorder(a[x].right);
	cout << char(x + 'A');
}


int main(void)
{
	int n; // 이진 트리의 노드의 개수
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A'; // 부모 노드 (0부터 시작)
		if (y == '.')
			a[x].left = -1; // 자식 노드가 없는 경우
		else
			a[x].left = y - 'A'; // 왼쪽 자식 노드 저장(정수형으로)
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