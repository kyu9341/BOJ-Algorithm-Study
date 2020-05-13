#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
const int MAX = 4000000;
vector<int> prime;
bool check[MAX + 1]; // �Ҽ��̸� false

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	check[1] = true;
	// �����佺�׳׽��� ü
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			prime.push_back(i); // �Ҽ��鸸 ���Ϳ� �߰�
			for (int j = i + i; j <= n; j += i) {
				check[j] = true; // �Ҽ��� �ƴϸ� true
			}
		}
	}

	int end = 0;
	int sum = 0;
	int ans = 0;
	// �Ҽ��� ���Ϳ��� �������� �˰���
	for (int start = 0; start < prime.size(); start++) {
		while (end < prime.size() && sum < n) {
			sum += prime[end++];
		}
		if (sum == n) ans++;
		sum -= prime[start];
	}

	cout << ans << '\n';
}