#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int n1, n2, t;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string order1, order2;
	cin >> n1 >> n2;
	cin >> order1 >> order2;
	cin >> t;

	map<char, bool> m; // 각 개미의 방향을 저장할 map

	for (int i = 0; i < order1.size(); i++) {
		m[order1[i]] = true;
	}
	for (int i = 0; i < order1.size(); i++) {
		m[order2[i]] = false;
	}

	reverse(order1.begin(), order1.end());
	string order = order1 + order2;
	while (t--) {
		for (int i = 0; i < order.size() - 1; i++) {
			if (m[order[i]] && !m[order[i + 1]]) { // 마주한 개미의 방향이 서로 다른 경우에 스와핑
				char tmp = order[i];
				order[i] = order[i + 1];
				order[i + 1] = tmp;
				i++;
			}
		}
		
	}
	cout << order << '\n';

}
