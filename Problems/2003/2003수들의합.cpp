#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
const int MAX = 10000;
int a[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int end = 0;
	int sum = 0;
	int ans = 0;

	// start를 차례로 증가시키며 반복
	for (int start = 0; start < n; start++) {
		while (sum < m && end < n) {
			// end를 가능한 만큼 이동
			sum += a[end++];
		}
		// 부분 합이 m일 때, 카운트 증가
		if (sum == m) {
			ans++;
		}
		sum -= a[start];
	}

	cout << ans << '\n';


}