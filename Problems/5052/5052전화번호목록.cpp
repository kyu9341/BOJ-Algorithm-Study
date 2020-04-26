#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cin.ignore();
		vector<string> numbers(n);
		for (int i = 0; i < n; i++)
			cin >> numbers[i];
		// 문자열을 오름차순 정렬
		sort(numbers.begin(), numbers.end());
		bool check = false;
		for (int i = 0; i < n - 1; i++) {
			// 정렬된 상태이므로 바로 다음 문자열이 현재 문자열로 시작하는지 확인
			if (numbers[i].size() <= numbers[i + 1].size()) {
				if (numbers[i] == numbers[i + 1].substr(0, numbers[i].size())) {
					cout << "NO" << '\n';
					check = true;
					break;
				}
			}
		}
		if(!check) cout << "YES" << '\n';
	}
}