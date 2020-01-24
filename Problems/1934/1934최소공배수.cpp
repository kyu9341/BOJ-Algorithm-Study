#include<iostream>

using namespace std;

int GCD(int, int);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // 테스트 케이스 수
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		int gcd = GCD(a, b);
		int lcm = (a * b) / gcd; // a*b = gcd * lcm 에서 유도

		cout << lcm << '\n';
	}

}

int GCD(int a, int b) // 최대 공약수 구하는 함수
{
	if (b == 0) // 유클리드 호제법 - GCD(a, b) -> a%b = r
		return a; // GCD(b, r) -> r = 0 일때, b가 최대공약수
	else return GCD(b, a % b);
}