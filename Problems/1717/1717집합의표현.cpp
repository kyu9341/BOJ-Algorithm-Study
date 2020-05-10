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
const int MAX = 1000000;
int parent[MAX + 1];

// ����� �θ� ���ϴ� �Լ�
int getParent(int x) {
	if (parent[x] == x)	return x;
	return parent[x] = getParent(parent[x]);
}

// �� ����� �θ� ��ġ�� �Լ�
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

// �� ����� �θ� ��ġ�ϴ��� Ȯ���ϴ� �Լ�
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
		if (op == 0) { // 0�� ��� �θ� ��ģ��.
			unionParent(a, b);
		}
		else if (op == 1) { // 1�� ��� �θ� ��ġ�ϴ��� Ȯ���Ѵ�.
			if (findParent(a, b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

}