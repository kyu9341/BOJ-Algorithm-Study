#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	reverse(a.begin(), a.end());

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (k / a[i] > 0)
		{
			cnt += k / a[i]; // 가장 큰 동전의 가치로 나눈 몫만큼 증가
			k %= a[i];  // 나눈 나머지를 저장
		}
	}

	cout << cnt << '\n';
}