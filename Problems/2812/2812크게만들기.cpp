#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

int n, k;
string number;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	cin >> number;
	deque<int> dq;

	string ans = "";
	int cnt = 0;
	for (int i = 0; i < number.size(); i++) {
		int now = number[i] - '0';
		if (dq.empty()) {
			dq.push_back(now);
		}
		else { // 비어있지 않은 경우 덱의 가장 뒤의 원소가 현재 원소보다 작다면 pop한다.
			while (!dq.empty() && dq.back() < now && cnt < k) {
				dq.pop_back();
				cnt++;
			}
			dq.push_back(now);
		}
		
	}
	// 아직 지우지 못한 만큼 뒤에서 지워준다.
	while (cnt != k) {
		dq.pop_back();
		cnt++;
	}
	// 앞에서부터 빼면서 ans에 누적
	while (!dq.empty()) {
		ans += dq.front() + '0';
		dq.pop_front();
	}

	cout << ans << '\n';

}