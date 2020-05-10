# Problem 1976

## 여행 가자

### 문제
동혁이는 친구들과 함께 여행을 가려고 한다. 한국에는 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 없을 수도 있다. 동혁이의 여행 일정이 주어졌을 때, 이 여행 경로가 가능한 것인지 알아보자. 물론 중간에 다른 도시를 경유해서 여행을 할 수도 있다. 예를 들어 도시가 5개 있고, A-B, B-C, A-D, B-D, E-A의 길이 있고, 동혁이의 여행 계획이 E C B C D 라면 E-A-B-C-B-C-B-D라는 여행경로를 통해 목적을 달성할 수 있다.

도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 동혁이의 여행 계획에 속한 도시들이 순서대로 주어졌을 때(중복 가능) 가능한지 여부를 판별하는 프로그램을 작성하시오.

### 입력
첫 줄에 도시의 수 N이 주어진다. N은 200이하이다. 둘째 줄에 여행 계획에 속한 도시들의 수 M이 주어진다. M은 1000이하이다. 다음 N * N 행렬을 통해 임의의 두 도시가 연결되었는지에 관한 정보가 주어진다. 1이면 연결된 것이고 0이면 연결이 되지 않은 것이다. A와 B가 연결되었으면 B와 A도 연결되어 있다. 마지막 줄에는 여행 계획이 주어진다.

### 출력
첫 줄에 가능하면 YES 불가능하면 NO를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1717>

### 예제 입력 1
3
3
0 1 0
1 0 1
0 1 0
1 2 3

### 예제 출력 1
YES

### solve
- 유니온 파인드를 사용하여 주어지는 도시의 연결 정보에 따라 두 도시의 부모를 합친다.
- 이 후, 모든 도시가 같은 부모를 가지는지 확인하여 같은 부모를 가진다면 여행이 가능한 것이다.

### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
const int MAX = 200;
int parent[MAX + 1];

// 노드의 부모를 찾는 함수
int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// 두 노드의 부모를 합치는 함수
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

// 두 노드의 부모가 같은지 확인하는 함수
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
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	// 도시의 연결 정보에 따라 부모를 합친다.
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int input;
			cin >> input;
			if (input) {
				unionParent(i, j);
			}
		}

	// 모든 도시가 같은 부모를 가지는지 확인
	int prev_parent;
	for (int i = 0; i < m; i++) {
		int route;
		cin >> route;
		if (i != 0 && prev_parent != parent[route]) {
			cout << "NO" << '\n';
			return 0;
		}
		prev_parent = parent[route];
	}
	cout << "YES" << '\n';
}
```
