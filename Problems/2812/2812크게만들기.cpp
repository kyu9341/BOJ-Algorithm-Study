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
		else { // ������� ���� ��� ���� ���� ���� ���Ұ� ���� ���Һ��� �۴ٸ� pop�Ѵ�.
			while (!dq.empty() && dq.back() < now && cnt < k) {
				dq.pop_back();
				cnt++;
			}
			dq.push_back(now);
		}
		
	}
	// ���� ������ ���� ��ŭ �ڿ��� �����ش�.
	while (cnt != k) {
		dq.pop_back();
		cnt++;
	}
	// �տ������� ���鼭 ans�� ����
	while (!dq.empty()) {
		ans += dq.front() + '0';
		dq.pop_front();
	}

	cout << ans << '\n';

}