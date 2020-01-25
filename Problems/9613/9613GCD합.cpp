#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) // 유클리드 호제법
{
	if (b == 0)	return a;
	else return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		long long sum = 0; // long long형으로 선언

		// 하나의 테스트 케이스의 원소를 저장할 벡터 생성
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				sum += gcd(v[i], v[j]);   // 최대공약수 : 유클리드 호제법 사용

		cout << sum << '\n';
	}
}