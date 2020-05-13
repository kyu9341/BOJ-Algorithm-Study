#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
const int MAX = 4000000;
vector<int> prime;
bool check[MAX + 1]; // 소수이면 false

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	check[1] = true;
	// 에라토스테네스의 체
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			prime.push_back(i); // 소수들만 벡터에 추가
			for (int j = i + i; j <= n; j += i) {
				check[j] = true; // 소수가 아니면 true
			}
		}
	}

	int end = 0;
	int sum = 0;
	int ans = 0;
	// 소수의 벡터에서 투포인터 알고리즘
	for (int start = 0; start < prime.size(); start++) {
		while (end < prime.size() && sum < n) {
			sum += prime[end++];
		}
		if (sum == n) ans++;
		sum -= prime[start];
	}

	cout << ans << '\n';
}