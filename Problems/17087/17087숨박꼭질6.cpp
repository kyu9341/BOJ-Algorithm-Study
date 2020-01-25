#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b) // 유클리드 호제법 (최대공약수)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, s; // n : 동생 수, s : 수빈이의 위치
	cin >> n >> s;
	vector<long long> v(n); // 수빈이의 위치와 동생의 위치를 담을 벡터
	for (long long i = 0; i < n; i++)
		cin >> v[i];
	v.push_back(s); // 수빈이의 위치 추가

	sort(v.begin(), v.end()); // 오름차순 정렬

	long long res = v[1] - v[0]; // 초기값 설정

	for (long long i = 1, j = i + 1; j < v.size(); i++, j++)
	{
		res = gcd(res, v[j] - v[i]); // 다음 원소와의 차이의 최대공약수(모든 차이 값의 최대공약수)
	}
		
	cout << res << '\n';
}