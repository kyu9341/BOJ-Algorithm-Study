# Problem 1717

## 집합의 표현

### 문제
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.

### 입력
첫째 줄에 n(1≤n≤1,000,000), m(1≤m≤100,000)이 주어진다. m은 입력으로 주어지는 연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0 a b의 형태로 입력이 주어진다. 이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다. a와 b는 n 이하의 자연수 또는 0이며 같을 수도 있다.

### 출력
1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)

### 문제 링크
<https://www.acmicpc.net/problem/1717>

### 예제 입력 1
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

### 예제 출력 1
NO
NO
YES

### solve
- 유니온 파인드 알고리즘의 기본 문제이다.
- 합집합 연산(0)은 유니온 파인드에서 두 부모를 합치는 연산을 수행하고,
- 두 원소가 같은 집합에 포함되어 있는지 여부는 두 노드의 부모가 같은지를 확인하면 된다.


### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
const int MAX = 1000000;
int parent[MAX + 1];

// 노드의 부모를 구하는 함수
int getParent(int x) {
	if (parent[x] == x)	return x;
	return parent[x] = getParent(parent[x]);
}

// 두 노드의 부모를 합치는 함수
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

// 두 노드의 부모가 일치하는지 확인하는 함수
bool findParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	int op, a, b;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	while (m--) {
		cin >> op >> a >> b;
		if (op == 0) { // 0인 경우 부모를 합친다.
			unionParent(a, b);
		}
		else if (op == 1) { // 1인 경우 부모가 일치하는지 확인한다.
			if (findParent(a, b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

}
```
