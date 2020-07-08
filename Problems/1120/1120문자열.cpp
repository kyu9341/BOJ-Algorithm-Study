#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a, b;
	cin >> a >> b;

	int min = 50;

	for (int i = 0; i < b.size() - a.size() + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[i + j]) {
				cnt++;
			}
		}
		if (min > cnt) min = cnt;
	}

	cout << min << '\n';

}