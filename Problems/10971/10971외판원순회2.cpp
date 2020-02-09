#include<iostream>
#include<algorithm>
#include<vector>
#include<climits> // INT_MAX 사용

using namespace std;
int w[11][11];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	vector<int> d(n);
	for (int i = 0; i < n; i++) // next_permutation을 사용하기 위한 배열
		d[i] = i; // 인덱스에 접근하기 위해 사용

	int ans = INT_MAX;
	do {
		int sum = 0;
		bool ok = true; // 길이 있는 경우
		for (int i = 0; i < n - 1; i++)
		{
			if (w[d[i]][d[i + 1]] == 0) ok = false; // 이어지는 길이 없는 경우
			else
				sum += w[d[i]][d[i + 1]]; // 길이 있으면 비용 누적
		}
		if (ok && w[d[n - 1]][d[0]] != 0) // 정상적인 경우(모든 길이 있고 마지막으로 돌아가는 길도 있는 경우)
		{
			sum += w[d[n - 1]][d[0]]; // 마지막 돌아가는 길 누적
			ans = min(ans, sum);
		}

	} while (next_permutation(d.begin(), d.end()));

	cout << ans << '\n';
}
