#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<map>
#include<cmath>

using namespace std;
const int MAX = 100000 + 1;
int F;
int setSize[MAX]; // 각 원소를 부모로 하는 집합의 원소 수
int parent[MAX]; // 부모를 저장할 배열

int getParent(int x) { // 부모를 찾는 함수
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) { // 부모를 합치며 집합의 원소 수 합침
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
		setSize[a] += setSize[b]; // 집합의 원소 수를 더해줌
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
			parent[i] = i; // 부모 배열 및 집합 크기 초기화
			setSize[i] = 1;
		}

		while (t--) {

			string a, b;
			cin >> a >> b;
			// map을 이용해서 
			if (m[a] == 0) m[a] = ++cnt;
			if (m[b] == 0) m[b] = ++cnt;
			int parentA = getParent(m[a]);
			int parentB = getParent(m[b]);
			if (parentA != parentB) { // 부모가 다르면
				unionParent(m[a], m[b]); // 부모를 합친다.
			}
			cout << setSize[min(parentA, parentB)] << '\n';

		}
	}

}