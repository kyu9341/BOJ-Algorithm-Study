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
		// ���ڿ��� �������� ����
		sort(numbers.begin(), numbers.end());
		bool check = false;
		for (int i = 0; i < n - 1; i++) {
			// ���ĵ� �����̹Ƿ� �ٷ� ���� ���ڿ��� ���� ���ڿ��� �����ϴ��� Ȯ��
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