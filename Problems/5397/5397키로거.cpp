#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;
int t;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	cin.ignore();
	// 두개의 스택으로 커서 위치를 구현
	stack<char> left, right; 

	while (t--) {
		string input;
		cin >> input;
		
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '<') {
				if (left.empty()) continue;
				right.push(left.top());
				left.pop();			
			}
			else if (input[i] == '>') {
				if (right.empty()) continue;
				left.push(right.top());
				right.pop();
			}
			else if (input[i] == '-') {
				if (left.empty()) continue;
				left.pop();
			}
			else {
				left.push(input[i]);
			}
		}
		while (!left.empty()) {
			right.push(left.top());
			left.pop();
		}
		while (!right.empty()) {
			cout << right.top();
			right.pop();
		}
		cout << '\n';

	}

}