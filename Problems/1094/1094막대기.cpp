#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

vector<int> v;

int stickSum() {
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		res += v[i];
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x;
	cin >> x; 
	v.push_back(64);

	while (true) {
		int sum = stickSum();
		if (sum == x) {
			break;
		}

		sort(v.begin(), v.end());
		if (sum > x) {
			v[0] /= 2;
			// 남은 막대 길이가 더 작으면 절반을 버리지 않음
			if (sum - v[0] < x) { 
				v.push_back(v[0]);
			}
		}
	}
	cout << v.size() << '\n';

}