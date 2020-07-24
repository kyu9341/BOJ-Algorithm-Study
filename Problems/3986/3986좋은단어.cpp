#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin.ignore();

	int ans = 0;
	while (n--) {
		string word;
		cin >> word;

		stack<char> s;
		for (int i = 0; i < word.size(); i++) {
			if (s.empty()) {
				s.push(word[i]);
			}
			else if (s.top() != word[i]) {
				s.push(word[i]);
			}
			else {
				while (!s.empty() && s.top() == word[i]) {
					s.pop();
				}
			}
		}
		if (s.empty()) ans++;
	}
	
	cout << ans << '\n';

}