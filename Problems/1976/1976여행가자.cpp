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

// ����� �θ� ã�� �Լ�
int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// �� ����� �θ� ��ġ�� �Լ�
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

// �� ����� �θ� ������ Ȯ���ϴ� �Լ�
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

	// ������ ���� ������ ���� �θ� ��ģ��.
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int input;
			cin >> input;
			if (input) {
				unionParent(i, j);
			}
		}
	
	// ��� ���ð� ���� �θ� �������� Ȯ��
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