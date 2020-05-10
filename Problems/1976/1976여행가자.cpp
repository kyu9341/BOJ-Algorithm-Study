#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cmath>

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