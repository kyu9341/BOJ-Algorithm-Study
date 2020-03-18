#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;

	if (n < m + k - 1 || n > m * k) // 불가능한 범위 처리
	{
		cout << -1 << '\n';
		return 0;
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	vector<int> s; // 구간을 나눌 지점을 저장할 벡터
	s.push_back(0); // 첫 구간의 시작
	s.push_back(k); // 첫 구간의 끝
	n -= k; // 남은 수의 개수
	m--; // 남은 구간 수

	int q = m == 0 ? 1 : n / m; // 남은 구간이 없다면 1
	int r = m == 0 ? 0 : n % m;
	
	for (int i = 0; i < m; i++) // 남은 구간 수 만큼
	{ // r(나머지)가 0이 될때까지 각 구간에 1씩 추가한다.
		s.push_back(s.back() + q + (r > 0 ? 1 : 0));  // 마지막 원소에 나눌 구간 크기만큼 더하여 추가
		if (r > 0) r--; // 나머지 감소
	}

	for (int i = 0; i < s.size() - 1; i++)
		reverse(a.begin() + s[i], a.begin() + s[i + 1]); // s에 저장된 구간으로 나누어 뒤집음
	
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << '\n';
}