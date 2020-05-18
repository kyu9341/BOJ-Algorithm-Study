#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<map>
#include<cmath>

using namespace std;
const int MAX = 100000 + 1;
int F;
int setSize[MAX]; // �� ���Ҹ� �θ�� �ϴ� ������ ���� ��
int parent[MAX]; // �θ� ������ �迭

int getParent(int x) { // �θ� ã�� �Լ�
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) { // �θ� ��ġ�� ������ ���� �� ��ħ
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
		setSize[a] += setSize[b]; // ������ ���� ���� ������
	}
	else {
		parent[a] = b;
		setSize[b] += setSize[a];
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> F;
	while (F--) {
		int cnt = 0;
		int t;
		cin >> t;

		map<string, int> m;
		for (int i = 0; i < MAX; i++) {
			parent[i] = i; // �θ� �迭 �� ���� ũ�� �ʱ�ȭ
			setSize[i] = 1;
		}

		while (t--) {

			string a, b;
			cin >> a >> b;
			// map�� �̿��ؼ� 
			if (m[a] == 0) m[a] = ++cnt;
			if (m[b] == 0) m[b] = ++cnt;
			int parentA = getParent(m[a]);
			int parentB = getParent(m[b]);
			if (parentA != parentB) { // �θ� �ٸ���
				unionParent(m[a], m[b]); // �θ� ��ģ��.
			}
			cout << setSize[min(parentA, parentB)] << '\n';

		}
	}

}