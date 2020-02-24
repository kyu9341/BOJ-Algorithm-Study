# Problem 1991

## 트리 순회

### 문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

예를 들어 위와 같은 이진 트리가 입력되면,

- 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
- 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
- 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)

### 입력
첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현된다.

### 출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
1991
### 문제 링크
<https://www.acmicpc.net/problem/1991>

### 예제 입력 1
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .

### 예제 출력 1
ABDCEFG
DBAECFG
DBEGFCA

### solve
- 트리의 순회 : dfs 3가지 출력 순서
- 프리오더 (전위 순회)
	- 노드 방문
	- 왼쪽 자식 노드를 루트로 하는 서브 트리 프리오더
	- 오른쪽 자식 노드를 루트로 하는 서브 트리 프리오더
- 인오더 (중위 순회)
	- 왼쪽 자식 노드를 루트로 하는 서브 트리 인오더
	- 노드 방문
	- 오른쪽 자식 노드를 루트로 하는 서브 트리 인오더
- 포스트오더 (후위 순회) : ** 자식에 대한 정보를 이용해 현재 노드의 값을 계산할 때 주로 사용(dp)
	- 왼쪽 자식 노드를 루트로 하는 서브 트리 포스트오더
	- 오른쪽 자식 노드를 루트로 하는 서브 트리 포스트오더
	- 노드 방문
- 트리를 구조체를 이용하여 각 노드의 좌측 자식 노드와 우측 자식 노드를 저장한다.
	- 노드가 문자로 입력되므로 루트 노드를 0으로 하여 정수로 바꿔 저장한다.
	- '.'이 입력되는 경우 자식 노드가 없다는 뜻이므로 -1을 저장한다.
- 각 순회 방식을 dfs를 이용하여 구현한다.

### 코드 설명
```C++
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
```
