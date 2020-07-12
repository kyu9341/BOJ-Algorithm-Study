#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string docs, word;
	getline(cin, docs);
	getline(cin, word);

	if (docs.size() < word.size()) {
		cout << 0 << '\n';
		return 0;
	}

	int cnt = 0;

	for (int i = 0; i < docs.size() - word.size() + 1; i++) {
		bool check = true;
		for (int j = 0; j < word.size(); j++) {
			if (docs[i + j] != word[j]) {
				check = false;
				break;
			}
		}
		if (check) {
			i += word.size() - 1;
			cnt++;
		}
	}

	cout << cnt << '\n';
}